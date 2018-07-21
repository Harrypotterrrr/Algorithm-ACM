#include<iostream>
#include<vector>     //std::vector
#include <algorithm> //std::count
using namespace std;

const int N = 100;
int dimes[] = { 1, 2, 5, 10 };
int arr[N + 1] = { 1 };
vector<int> vv;

int coinExchangeRecursion(int n, int m) //递归方式实现，更好理解
{
	if (n == 0) {
		int i;
		for (i = 0; i < sizeof(dimes) / sizeof(int); i++) {
			int cnt = count(vv.begin(), vv.end(), dimes[i]);
			cout << dimes[i] << ": " << cnt << "\t";
		}
		cout << endl;
		return 1;
	}   //跳出递归的条件
	if (n < 0 || m == 0)
		return 0;
	vv.push_back(dimes[m - 1]);
	int yes = coinExchangeRecursion(n - dimes[m - 1], m);
	vv.pop_back();
	int no = coinExchangeRecursion(n, m - 1);
	return (no + yes);
	//分为两种情况，如果没有换当前硬币，那么是多少？加上，如果换了当前硬币，总值减少，此时又是多少种兑换方法？
}

int coinExchange(int n)   //非递归实现
{
	int i, j;
	for (i = 0; i < sizeof(dimes) / sizeof(int); i++)   //i从0 ~ 3     因为每个arr[j]都要有一次是假设兑换了dimes[i]，所以我们要遍历一次
	{
		for (j = dimes[i]; j <= n; j++)
			//求，arr[j]的时候，可以看出arr[j] = arr[j] + arr[j-dimes[i]]，
			//对应着上面的递归方式：arr[j]就是 coinExchangeRecursion(n, m-1)，
			//arr[j-dimes[i]]就是coinExchangeRecursion(n-dimes[m-1], m)
			arr[j] += arr[j - dimes[i]];
	}
	return arr[n];
}

int main(int argc, char *argv[])
{
	int num = coinExchangeRecursion(N, 4);
	cout << num << endl;

	int num2 = coinExchange(N);
	cout << num2 << endl;

	return 0;
}