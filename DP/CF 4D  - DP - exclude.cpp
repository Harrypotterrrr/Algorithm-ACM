/************************************************
Problem: 		CF 4D  Mysterious Present
Algorithm: 		DP
Difficulty: 	++
Significance:	+++
Remark:			DF solution and ouput the detail by dfs
				Vector exclude first constriction
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define INF 0X3f3f3f3f
using namespace std;
typedef long long ll;
struct Node
{
	int minn; 
	int weigth;
	int height;
	int num;
	Node() {};
	Node(int w, int h, int k)
	{
		minn = min(w, h);
		weigth = w;
		height = h;
		num = k;
	}
};
bool cmp(Node &a, Node&b)
{
	return a.minn < b.minn;
}
int n, w, h;

struct List
{
	int pre;
	int length;
	int no;
};
List ans[1000005];

void dfs(int k)
{
	if (ans[k].pre == -1) {
		printf("%d ", ans[k].no);
		return;
	}
	dfs(ans[k].pre);
	printf("%d ", ans[k].no);
}

int main()
{
	while (scanf("%d%d%d", &n,&w,&h) != EOF) {
		int tw,th;
		vector<Node>V;
		memset(ans, -1, sizeof(ans));
		
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &tw, &th);
			if(w < tw && h < th)
				V.push_back(Node(tw, th, i + 1));
		}
		if (V.size() == 0) {
			printf("0\n");
			continue;
		}

		sort(V.begin(), V.end(), cmp);
		int ans_max = 1, ans_index = 0;
		ans[0].length = 1;
		ans[0].no = V[0].num;
		for (int i = 1,j; i < V.size(); i++) {
			int tmp_max = 0, tmp_index = -1;		// IMPORTANT!!
			for (j = 0; j < i; j++) {
				if (V[i].weigth > V[j].weigth && V[i].height > V[j].height) {
					if (tmp_max < ans[j].length) {
						tmp_max = ans[j].length;
						tmp_index = j;
					}
				}
			}
			ans[i].length = tmp_max + 1;
			ans[i].pre = tmp_index;
			ans[i].no = V[i].num;
			if (ans_max < ans[i].length) {
				ans_max = ans[i].length;
				ans_index = i;
			}
		}

		printf("%d\n", ans[ans_index].length);
		dfs(ans_index);
		puts("");
	}
	return 0;
}


//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//#define INF 0X3f3f3f3f
//using namespace std;
//typedef long long ll;
//struct Node
//{
//	int minn;
//	int weigth;
//	int height;
//	int num;
//	Node() {};
//	Node(int w, int h, int k)
//	{
//		minn = min(w, h);
//		weigth = w;
//		height = h;
//		num = k;
//	}
//};
//bool cmp(Node &a, Node&b)
//{
//	return a.minn < b.minn;
//}
//int n, w, h;
//
//struct List
//{
//	int pre;
//	int length;
//	int no;
//};
//List ans[1000005];
//
//void dfs(int k)
//{
//	if (ans[k].pre == -1) {
//		//printf("%d ", k);
//		return;
//	}
//	dfs(ans[k].pre);
//	printf("%d ", ans[k].no);
//}
//
//int main()
//{
//	while (scanf("%d%d%d", &n, &w, &h) != EOF) {
//		int tw, th;
//		vector<Node>V;
//		memset(ans, -1, sizeof(ans));
//
//		V.push_back(Node(w, h, 0));
//		for (int i = 0; i < n; i++) {
//			scanf("%d%d", &tw, &th);
//			if (w < tw && h < th)
//				V.push_back(Node(tw, th, i + 1));
//		}
//		sort(V.begin() + 1, V.end(), cmp);
//
//		int ans_max = -1, ans_index = 0;
//		ans[0].length = 0;
//		for (int i = 1, j; i < V.size(); i++) {
//			int tmp_max = -1, tmp_index = -1;
//			for (j = 0; j < i; j++) {
//				if (V[i].weigth > V[j].weigth && V[i].height > V[j].height) {
//					if (tmp_max < ans[j].length) {
//						tmp_max = ans[j].length;
//						tmp_index = j;
//					}
//				}
//			}
//			ans[i].length = tmp_max + 1;
//			ans[i].pre = tmp_index;
//			ans[i].no = V[i].num;
//			if (ans_max < ans[i].length) {
//				ans_max = ans[i].length;
//				ans_index = i;
//			}
//		}
//		if (ans_index == 0)
//			printf("0");
//		else {
//			printf("%d\n", ans[ans_index].length);
//			dfs(ans_index);
//		}
//		puts("");
//	}
//	return 0;
//}