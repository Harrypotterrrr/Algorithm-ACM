#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;

struct PII{
    int x;
    int y;
} pii[50050];
vector<int> lnk[50050];
int arr[50050];
int n;
bool operator <(const PII &a,const PII &b){
    return a.y>b.y;
}
bool cmp1(const int &a,const int &b){
    return pii[a].x<pii[b].x;
}
bool cmp2(const int &a,const int &b){
    return pii[a].y<pii[b].y;
}

int dis[50050];
int vis[50050];
ll dijk(){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[1]=0;
    ll ans=0;
    priority_queue<PII> pq;
    PII temp,t;
    temp.x=1;temp.y=0;
    pq.push(temp);
    while(!pq.empty()){
        t=pq.top();
        pq.pop();
        if(vis[t.x])continue;
        vis[t.x]=1;
        for(auto it=lnk[t.x].begin();it!=lnk[t.x].end();it++){
            if(dis[*it]>dis[t.x]+min(abs(pii[*it].x-pii[t.x].x),abs(pii[*it].y-pii[t.x].y))){
                dis[*it]=dis[t.x]+min(abs(pii[*it].x-pii[t.x].x),abs(pii[*it].y-pii[t.x].y));
                temp.x=*it;
                temp.y=dis[*it];
                pq.push(temp);
            }
        }
    }
    for(int i=1;i<=n;i++){
        //cout<<dis[i]<<endl;
        ans+=dis[i];
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            lnk[i].clear();
        for(int i=1;i<=n;i++)
            arr[i]=i;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&pii[i].x,&pii[i].y);
        }
        sort(arr+1,arr+1+n,cmp1);
        for(int i=1;i<=n;i++){
            if(i>1)
                lnk[arr[i]].push_back(arr[i-1]);
            if(i<n)
                lnk[arr[i]].push_back(arr[i+1]);
        }
        sort(arr+1,arr+1+n,cmp2);
        for(int i=1;i<=n;i++){
            if(i>1)
                lnk[arr[i]].push_back(arr[i-1]);
            if(i<n)
                lnk[arr[i]].push_back(arr[i+1]);
        }
        printf("Case #%d:\n",tt);
        cout<<dijk()<<endl;
    }
    return 0;
}

