#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	double Max(double,double,double);
	double Min(double,double,double);
	int D;
	double start[3],end[3];
	const double v_s=6.0,v_m=6.0/60,v_h=30.0/3600;
	const double v_sm = v_s - v_m;
	const double v_sh = v_s - v_h;
	const double v_mh = v_m - v_h;
	const double T_sm = 360.0 / v_sm;
	const double T_sh = 360.0 / v_sh;
	const double T_mh = 360.0 / v_mh;
	while(scanf("%d",&D),D != -1){
		double sum=0.0;
		double T_D_sm = D / v_sm;
		double T_D_sh = D / v_sh;
		double T_D_mh = D / v_mh;
		double T_d_sm = (360.0-D) / v_sm;
		double T_d_sh = (360.0-D) / v_sh;
		double T_d_mh = (360.0-D) / v_mh;
		for(start[1]=T_D_sh, end[1]=T_d_sh;end[1]<=43200.0001;start[1]+=T_sh,end[1]+=T_sh){
			for(start[0]=T_D_sm,end[0]=T_d_sm;end[0]<=43200.0001;start[0]+=T_sm,end[0]+=T_sm){
				if(end[1] < start[0])
					break;
				else if(end[0] < start[1])
					continue;
				for(start[2]=T_D_mh,end[2]=T_d_mh;end[2]<=43200.0001;start[2]+=T_mh,end[2]+=T_mh){
					if(start[2] > end[0] || start[2] > end[1])
						break;
					else if(end[2] < start[0] || end[2] < start[1])
						continue;
					double START = Max(start[0],start[1],start[2]);
					double END = Min(end[0],end[1],end[2]);
					sum += END - START;
				}
			}
		}
		printf("%.3lf\n",sum/432.0);	
	} 
}

double Max(double x,double y,double z){
	double temp = x > y ? x : y;
	return temp > z ? temp : z; 
}

double Min(double x, double y,double z){
	double temp = x < y ? x : y;
	return temp < z ? temp : z;
}
