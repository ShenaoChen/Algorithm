#include<iostream>
#include<cstring>

using namespace std;

const int N=510,M=10010;

struct edge{
    int a,b,c;
}e[M];

int n,m,k;
int dist[N];
int last[N];

void bellman_ford(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=1;i<=k;i++){
        memcpy(last,dist,sizeof dist);
        for(int j=1;j<=m;j++){
            auto t=e[j];
            dist[t.b]=min(dist[t.b],last[t.a]+t.c);
        }
    }
    if(dist[n]>0x3f3f3f3f/2) cout<<"impossible"<<endl;
    else cout<<dist[n]<<endl;
}

int main(){
    int a,b,c;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        e[i]={a,b,c};
    }

    bellman_ford();

    return 0;
}