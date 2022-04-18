#include<iostream>

using namespace std;

const int N=10;
int path[N],n;
bool vis[N];
void dfs(int x){
    if(x==n){
        for(int i=0;i<n;i++)
            printf("%d ",path[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            path[x]=i;
            dfs(x+1);
            vis[i]=0;
        }
    }
}

int main(){
    cin>>n;
    dfs(0);
    return 0;
}