#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
double x1,y_1,dx1,dy_1,x2,y2,dx2,dy2,Y,X;
bool judge(){
	if(X * (x1 - x2) + Y * (y_1 - y2) < 1e-8 ){
		double ans = sqrt((x1-x2)*(x1-x2) + (y_1-y2)*(y_1-y2));
		printf("%.9lf\n",ans);
		return true;
	}
	return false;
}
int main()
{
//	freopen("r.txt","r",stdin);
//	freopen("w_wa.txt","w",stdout);
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y_1,&dx1,&dy_1,&x2,&y2,&dx2,&dy2) != EOF){
		Y = dy2 - dy_1;
		X = dx2 - dx1;
		if(fabs(dx2 - dx1) < 1e-8){
			if(judge())
				continue;
			printf("%.9lf\n",fabs(x1 - x2));
			continue;
		}
		if(judge())
			continue;
		double k = Y / X;
		double b = y2 - k * x2;
		double d = fabs(k * x1 - y_1 + b) / sqrt(k * k + 1);
		printf("%.9lf\n",d);
	}
	return 0;
}
