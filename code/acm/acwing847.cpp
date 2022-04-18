#include<cstring>
#include<iostream>
#include<queue>

using namespace std;

const int N=1e5+5;

int h[N],e[N],ne[N],d[N];
int n,m,idx;
bool vis[N];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void bfs(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int i=h[tmp];i!=-1;i=ne[i]){
            int j=e[i];
            if(vis[j])  continue;
            vis[j]=1;
            d[j]=d[tmp]+1;
            q.push(j);
        }
    }
    if(!vis[n])
        d[n]=-1;
    cout<<d[n]<<endl;
}

int main(){
    int a,b;
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    bfs();
    return 0;
}