#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define Inf 0X7fffffff
#define MaxNM 100009
using namespace std;
int N,M,C;
int s,t;
int tolayer[MaxNM];
int tonode[MaxNM];
int vis[MaxNM];
int adj[MaxNM];
struct Edge
{
    int to;
    int wei;
    int next;
}E[MaxNM];
int d[MaxNM];
struct qnode
{
    int node;
    int dis;
    qnode(){}
    qnode(int nod,int di):node(nod),dis(di){}
    bool operator <(const qnode &a)
    {
        return dis<a.dis;
    }
};
bool djs()
{
    for(int i=1;i<=N;i++)
    {
        vis[i]=0;
        d[i]=Inf;
    }
    d[s]=0;
    queue<qnode>Q;
    for(int g=1;g<=N;g++)
    Q.push(qnode(g,d[g]));
    for(int j=1;j<=N;j++)
    {
        int k=-1;
        /*int min=Inf;
        for(int jj=1;jj<=N;jj++)
        if(!vis[jj] && d[jj]<min)
        {
            min=d[jj];
            k=jj;
        }*/
        qnode q=Q.front();
         if(!vis[q.node]) k=q.node;
         if(k==-1) return false;
        vis[k]=1;
        Q.pop();
        //cout<<\"k:\"<<k<<endl;

        for(int xx=adj[k];xx!=-1;xx=E[xx].next)
        {
            int x=E[xx].to;
            if(!vis[x] && d[x]>d[k]+E[xx].wei)
            {
                d[x]=E[xx].wei+d[k];
                Q.push(qnode(x,d[x]));
                int y=tolayer[k];
            int y1=y-1,y2=y+1;
            if(y1>0 && d[tonode[y1]]>C+d[k]) {d[tonode[y1]]=C+d[k],Q.push(qnode(tonode[y1],d[tonode[y1]]));}
            if(y2<=N && d[tonode[y2]]>C+d[k]) {d[tonode[y2]]=C+d[k];Q.push(qnode(tonode[y2],d[tonode[y2]]));}
            }
        }

    }
    return true;
}
int c;
int main()
{
    int u , v ,w;
    int T,a;
    int cas=0;
    scanf("%d",&T);
    while(T--)
    {
        c=0;
        cas++;
        scanf("%d%d%d",&N,&M,&C);
        s=1;
        t=N;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&a);
            tonode[a]=i;
            tolayer[i]=a;
        }
        memset(adj,1,sizeof adj);
        for(int k=1;k<=M;k++)
        {
            scanf("%d%d%d",&u,&v,&w);
            E[c].to=v;
            E[c].wei=w;
            E[c].next=adj[u];
            adj[u]=c++;
        }
        if(djs()) printf("Case #%d: %d\n",cas,d[N]);
        else printf("Case #%d: %d\n",cas,d[N]);
    }
    return 0;
}
