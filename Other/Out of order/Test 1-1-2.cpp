#include <iostream>
using namespace std;

int sum10[10] = { 0 }, ctr[10] = { 0 };
int solve(int n)
{
	if (n == 1) {
		sum10[1] = n;
		return n;
	}
	int t10 = 1;
	for (int i = 0; i < n - 1; i++)
		t10 *= 10;
	sum10[n] = 10 * solve(n - 1) + t10;
	return sum10[n];
}
void CalcNum(int &n, int k, int tmp10)
{
	int high = n / tmp10;

	for (int i = 0; i < high; i++) {
		for (int j = 0; j < 10; j++)
			ctr[j] += sum10[k - 1];
		ctr[i] += tmp10;
	}

	n = n % tmp10;
	ctr[high] += n + 1;
	ctr[0] -= tmp10 ;
}
int main()
{
	int n;
	cin >> n;
	int tmp = n, k = 0, tmp10 = 1;
	while (tmp) {
		k++;
		tmp /= 10;
		tmp10 *= 10;
	}
	tmp10 /= 10;
	solve(k);
	//for (int i = 0; i < 10; i++)
	//	cout << i << ":" << sum10[i] << endl;

	for (int i = k, tmp = n; i > 0; i--, tmp10 /= 10)
		CalcNum(tmp, i, tmp10);
	
	for (int i = 0; i < 10; i++)
		cout << ctr[i] << endl;
	return 0;
}
