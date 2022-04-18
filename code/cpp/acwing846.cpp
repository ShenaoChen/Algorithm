#include<cstring>
#include<iostream>

using namespace std;

const int N=1e5+5,M=N*2;

int h[N],e[M],ne[M];
int idx,ans=N,n;
bool vis[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dfs(int u){
    int res=1,tmp=0;
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(vis[j])
            continue;
        vis[j]=1;
        int s=dfs(j);
        tmp=max(tmp,s);
        res+=s;
    }
    tmp=max(tmp,n-res);
    ans=min(ans,tmp);
    return res;
}

int main(){
    int a,b;
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}