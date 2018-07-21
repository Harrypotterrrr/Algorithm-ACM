#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MODN 1000000007
typedef long long ll;
int mod;

struct matrix{
    ll mat[20][20];
    int r;
    matrix(){
        memset(mat,0,sizeof(mat));
    }


};
matrix operator *(matrix &a,matrix &b){
    matrix ans;
    ans.r=a.r;
    for(int i=0;i<a.r;i++)
    for(int j=0;j<a.r;j++)
    for(int k=0;k<a.r;k++){
        ans.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
        ans.mat[i][j]%=MODN;
    }
    return ans;
}
char str[5005000];
int counter[22];
int n;
matrix powmod(int ct,int rnk){
    matrix ans;
    for(int i=0;i<mod;i++)
        ans.mat[i][i]=1;
    ans.r=mod;
    matrix a;
    a.r=mod;
    for(int i=0;i<mod;i++)
    for(int j=0;j<10;j++){
        a.mat[(i+j*rnk)%mod][i]++;
    }
    while(ct){
        if(ct&1){
            ans=ans*a;
        }
        a=a*a;
        ct/=2;
    }
    return ans;
}
ll solve(){
    int rst=0;
    int rnk=1;
    for(int i=n-1;i>=0;i--){
        if(str[i]=='X')
            counter[rnk]++;
        else{
            rst+=rnk*(str[i]-'0');
            rst%=mod;
        }
        rnk*=10;
        rnk%=mod;
    }
    matrix ans=powmod(counter[0],0);
    for(int i=1;i<mod;i++){
        matrix temp=powmod(counter[i],i);
        ans=ans*temp;
    }
    return ans.mat[(mod-rst)%mod][0];


}


int main(){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d%d",&n,&mod);
        scanf("%s",str);
        memset(counter,0,sizeof(counter));
        ll ans=solve();
        printf("Case #%d:\n",tt);
        printf("%lld\n",ans);
    }
    return 0;
}

