#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int num, ans = 1;
		cin >> num;
		for (int i = 2; i*i <= num && num > 1; i++) {
			bool flag = false;
			while (!(num % i)) {
				flag = !flag;
				num /= i;
			}
			if (flag)
				ans *= i;
		}
		if (num > 1)
			ans *= num;
		cout << "Case #" << i<<":" << endl;
		cout << ans << endl;
	}
}