#include<iostream>
#include<cstring>

using namespace std;

const int N=510;

int g[N][N];
int dist[N];
bool st[N];

int dijkstra(int n){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;

    for(int i=1;i<=n;i++){
        int t=-1;
        for(int j=1;j<=n;j++)
            if(!st[j]&&(t==-1||dist[t]>dist[j]))
                t=j;

        for(int j=1;j<=n;j++)
            dist[j]=min(dist[j],dist[t]+g[t][j]);
    }

    if(dist[n]==0x3f3f3f3f) return -1;
    else return dist[n];

}

int main(){
    int n,m;
    int a,b,w;

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[i][j]=0x3f3f3f3f;
    
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&w);
        g[a][b]=min(g[a][b],w);
        g[b][a]=min(g[b][a],w);
    }

    cout<<dijkstra(n)<<endl;

    return 0;
}