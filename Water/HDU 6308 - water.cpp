/************************************************
Problem: 		HDU 6308 Time Zone
Algorithm: 		water
Difficulty: 	
Significance:	
Remark:
*************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <bits\stdc++.h>

#define DAY_MIN 1440
#define eps 1e-8
using namespace std;
int num[1000005] = { 0 };
int main()
{
	int T;
	int hour, min;
	double bias;
	char sign;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &hour, &min);
		for (int i = 0; i < 4; i++)
			getchar();
		sign = getchar();
		scanf("%lf", &bias);
		int sum = hour * 60 + min;

		if (sign == '+') {
			double tmp = 60 * (bias + eps - 8);
			if (fabs(tmp) > sum)
				sum += DAY_MIN;
			sum += tmp;
		}
		else if (sign == '-') {
			double tmp = 60 * (bias - eps + 8);
			if (fabs(tmp) > sum)
				sum += DAY_MIN;
			sum -= 60 * (bias - eps + 8);
		}

		hour = (sum + DAY_MIN) / 60;
		min = (sum + DAY_MIN) % 60;
		while (hour > 23)
			hour -= 24;

		if (hour < 10)
			printf("0%d:", hour);
		else
			printf("%d:", hour);
		if (min < 10)
			printf("0%d\n", min);
		else
			printf("%d\n", min);
	}
	return 0;
}
/*
500
0 0 UTC+0.1
0 0 UTC-0.1
23 59 UTC+0.1
23 59 UTC-0.1
11 15 UTC+13.0
11 15 UTC+13.1
11 15 UTC+13.2
11 15 UTC+13.3
11 15 UTC+13.4
11 15 UTC+13.5
11 15 UTC+13.6
11 15 UTC+13.7
11 15 UTC+13.8
11 15 UTC+13.9
11 15 UTC+14
11 15 UTC-13.0
11 15 UTC-13.1
11 15 UTC-13.2
11 15 UTC-13.3
11 15 UTC-13.4
11 15 UTC-13.5
11 15 UTC-13.6
11 15 UTC-13.7
11 15 UTC-13.8
11 15 UTC-13.9
11 15 UTC-14
11 15 UTC-0.0
11 15 UTC-0.1
11 15 UTC-0.2
11 15 UTC-0.3
11 15 UTC-0.4
11 15 UTC-0.5
11 15 UTC-0.6
11 15 UTC-0.7
11 15 UTC-0.8
11 15 UTC-0.9
11 15 UTC-8.0
11 15 UTC-8.1
11 15 UTC-8.2
11 15 UTC-8.3
11 15 UTC-8.4
11 15 UTC-8.5
11 15 UTC-8.6
11 15 UTC-8.7
11 15 UTC-8.8
11 15 UTC-8.9
11 15 UTC-10.0
11 15 UTC-10.1
11 15 UTC-10.2
11 15 UTC-10.3
11 15 UTC-10.4
11 15 UTC-10.5
11 15 UTC-10.6
11 15 UTC-10.7
11 15 UTC-10.8
11 15 UTC-10.9
11 15 UTC+0.0
11 15 UTC+0.1
11 15 UTC+0.2
11 15 UTC+0.3
11 15 UTC+0.4
11 15 UTC+0.5
11 15 UTC+0.6
11 15 UTC+0.7
11 15 UTC+0.8
11 15 UTC+0.9
11 15 UTC+8.0
11 15 UTC+8.1
11 15 UTC+8.2
11 15 UTC+8.3
11 15 UTC+8.4
11 15 UTC+8.5
11 15 UTC+8.6
11 15 UTC+8.7
11 15 UTC+8.8
11 15 UTC+8.9
11 15 UTC+10.0
11 15 UTC+10.1
11 15 UTC+10.2
11 15 UTC+10.3
11 15 UTC+10.4
11 15 UTC+10.5
11 15 UTC+10.6
11 15 UTC+10.7
11 15 UTC+10.8
11 15 UTC+10.9
*/