#include<iostream>  
#include<iomanip>  
using namespace std;  
  
double calculate(double a,double b)  
{  
    double temp=(a-b)>0?(a-b):(b-a);  
      
    return temp>(360.0-temp)?(360.0-temp):temp;  
}  
  
int main()  
{  
    double degree,flag;  
    const double h_degree=360/(12*60*60.0),m_degree=360/(60*60.0),s_degree=360/60.0;  
    unsigned int rem_h=1,rem_m=1,rem_s=1,count=0;  
  
    while(cin>>degree && degree>=0.0)  
    {  
        while(rem_h<=12*60*60)  
        {  
            if( calculate(rem_h*h_degree,rem_m*m_degree)>=degree )  
                if( calculate(rem_m*m_degree,rem_s*s_degree)>=degree )  
                    if( calculate(rem_h*h_degree,rem_s*s_degree)>=degree )  
                        count++;  
  
            rem_h++;  
            rem_m++;  
            rem_s++;  
			rem_s %= 60;
			rem_m %= 3600;
        }  
  
        flag=count/(12*60*60.0)*100.0;  
        cout<<setiosflags(ios::fixed);  
        cout<<setprecision(3);  
        cout<<flag<<endl;  
  
        rem_h=rem_m=rem_s=1;  
        count=0;  
    }  
  
    return 0;  
}  
