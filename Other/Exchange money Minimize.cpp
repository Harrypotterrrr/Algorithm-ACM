#include <iostream>
#include <algorithm> //std::count
using namespace std;
#define MAX 0X3F3F3F3F
#define N 1000
int dimes[] = { 3,12,24,31,33 };
int arr[1000];

void Solve(int n)
{
	memset(arr, MAX, sizeof(arr));
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		int minn = MAX;
		for (int j = 0; j < sizeof(dimes) / sizeof(int) && i >= dimes[j]; j++)
				minn = minn <= arr[i - dimes[j]] ? minn : arr[i - dimes[j]];
		if (minn != MAX)
			arr[i] = minn + 1;
		else
			arr[i] = MAX;
	}
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	Solve(n);
	for (int i = 0; i <= n; i++)
		if (arr[i] == MAX)
			cout << i << ":" << 0 << endl;
		else
			cout << i << ":" << arr[i] << endl;
	return 0;
}