#include <bits/stdc++.h>
using namespace std;
int w[5];
int start,End;
struct state {
	int nw_num;
	int take;
	bool operator < (const state & a) const
	{
		return take > a.take;
	}
};

int main()
{
	int n;
	cin >> n;
	int flag[1010] = { false };

	for (int k = 1; k <= n; k++)
	{
		memset(flag, 0x3f3f3f3f, sizeof(flag));
		cin >> start >> End;
		cin >> w[0] >> w[1] >> w[2];
		priority_queue<state> Q;
		state z = { start,0 };
		Q.push(z);
		int answer = -1;
		int step = 0;
		if (!(!(start % 2) && (End % 2))){
			while (!Q.empty())
			{
				state nw = Q.top();
				Q.pop();
				if (nw.nw_num == End) {
					answer = nw.take;
					break;
				}

				int num1 = nw.nw_num * 2;
				int cost1 = nw.take + w[0];
				state t1 = { num1,cost1 };

				int num2 = nw.nw_num + 2;
				int cost2 = nw.take + w[1];
				state t2 = { num2,cost2 };

				int num3 = nw.nw_num - 2;
				int cost3 = nw.take + w[2];
				state t3 = { num3,cost3 };

				if (num1 <=1000 && num1 >= 1 && cost1 <= flag[num1]) {
					Q.push(t1);
					flag[num1] = cost1;
				}
				if (num2 <= 1000 && num2 >= 1 && cost2 <= flag[num2]) {
					Q.push(t2);
					flag[num2] = cost2;
				}
				if (num3 <= 1000 && num3 >= 1 && cost3 <= flag[num3]) {
					Q.push(t3);
					flag[num3] = cost3;
				}
			}
		}
		

		cout << "Case #" << k << ":" << endl;
		cout << answer << endl;
	}
	return 0;
}