/************************************************
Problem: 		HDU 1427 速算24点
Algorithm: 		DFS
Difficulty: 	++
Significance:	+
Remark:			liable to make mistake for searching strategy
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
char ch[8][2];
bool flag;

struct Node
{
	bool flag;
	int num;
	Node(int num, bool flag = false) {
		this->flag = flag;
		this->num = num;
	}
};
vector<Node>V;

int opt(int x, int y, int k)
{
	if (k == 0)
		return x + y;
	if (k == 1)
		return x - y;
	if (k == 2)
		return x * y;
	if (k == 3)
		return x / y;
}
void dfs(int n)
{
	if (flag || n == 1) {
		if ((V.end() - 1)->num == 24)
			flag = true;
		return;
	}
	for (int i = 0; i < V.size(); i++) {
		if (V[i].flag)
			continue;
		for (int j = 0; j < V.size(); j++)
			if (i != j && !(V[j].flag)) {
				for (int u = 0; u < 4; u++) {
					if (u == 3 && (!V[j].num || (V[i].num % V[j].num)))
						break;
					V[i].flag = true;
					V[j].flag = true;
					V.push_back(Node(opt(V[i].num, V[j].num, u)));
					dfs(n - 1);
					V.pop_back();
					V[i].flag = false;
					V[j].flag = false;
				}
			}
	}
}

void Convert()
{
	for (int i = 0; i < 4; i++) {
		if (strlen(ch[i]) != 1)
			V.push_back(Node(10));
		else if (ch[i][0] >= '0' && ch[i][0] <= '9')
			V.push_back(Node(ch[i][0] - '0'));
		else if (ch[i][0] == 'A')
			V.push_back(Node(1));
		else if (ch[i][0] == 'J')
			V.push_back(Node(11));
		else if (ch[i][0] == 'Q')
			V.push_back(Node(12));
		else if (ch[i][0] == 'K')
			V.push_back(Node(13));
	}
}
int main()
{
	while (cin >> ch[0] >> ch[1] >> ch[2] >> ch[3]) {
		flag = false;

		Convert();
		dfs(4);

		if (flag)
			cout << "Yes\n";
		else
			cout << "No\n";

		V.clear();
	}
}