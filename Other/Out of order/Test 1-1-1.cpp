#include <iostream>
using namespace std;


int main()
{
	int n, ctr[10] = { 0 };
	cin >> n;
	int k = n, m = 0;
	//int c[6] = { 0 };
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1, ct = 0; j < 100000; ct++, j*=10) {
	//		if (i >= j && i / j % 10 == 1)
	//			c[ct] ++;
	//	}
	//}
	//for(int i=0 ; i<5 ; i++)
	//	cout << c[i] << endl;


	while (k) {
		k /= 10;
		m++;
	}
	for (int i = 0, tmp10 = 1; i < m; i++, tmp10 *= 10) {
		int t = n / tmp10 % 10;
		int front = n / tmp10 / 10;
		int back = n % tmp10;

		for (int j = 0; j < 10; j++) {
			if (t > j)
				ctr[j] += (front + (j != 0)) * tmp10;
			else if (t == j)
				ctr[j] += (front - (j == 0)) * tmp10 + back + 1;
			else
				ctr[j] += front * tmp10;
		}
	}
	for (int i = 0; i < 10; i++)
		cout/*<<i<<"出现的次数:"*/<< ctr[i] <<endl;
	return 0;
}