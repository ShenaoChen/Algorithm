#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=1e5+5 , M=2e5+5 , INF=0x3f3f3f3f;

struct Edge{
    int a,b,w;
    bool operator<(const Edge &b)const{
        return w<b.w;
    }
}edges[M];

int n,m;
int s[N];

int find(int x){
    if(s[x]!=x)
        s[x]=find(s[x]);
    return s[x];
}

int kruskal(){
    sort(edges, edges+m);
    for(int i=1;i<=n;i++) s[i]=i;

    int res=0, cnt=0;
    for(auto edge : edges){
        int a=edge.a, b=edge.b, w=edge.w;
        a=find(a), b=find(b);
        if(a!=b){
            s[a]=b;
            res+=w;
            cnt++;
        }
    }

    if(cnt<n-1) return INF;
    return res;
}

int main(){
    int u,v,w;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++){
        scanf("%d%d%d",&u,&v,&w);
        edges[i]={u,v,w};
    }

    int t = kruskal();

    if(t == INF) cout<<"impossible"<<endl;
    else cout<<"t"<<endl;

    return 0;
}