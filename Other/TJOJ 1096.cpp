#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define MID 10200
typedef long long ll;
int dp[105][MID*2+105];
int main(){
    int t;
    int n,m;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        dp[0][MID]=1;
        int w;
        for(int i=1;i<=n;i++){
            scanf("%d",&w);
            for(int j=100;j<MID*2;j++){
                dp[i][j]=dp[i-1][j]||dp[i-1][j-w]||dp[i-1][j+w];
            }
        }

        printf("Case #%d:\n",tt);
        scanf("%d",&m);
        while(m--){
            scanf("%d",&w);
            if(dp[n][w+MID]||(dp[n][w+MID-1])&&dp[n][w+MID+1])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}

