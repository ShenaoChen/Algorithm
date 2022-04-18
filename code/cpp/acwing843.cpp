#include<iostream>

using namespace std;

const int N=20;

int n;
char g[N][N];
bool col[N],dg[N],udg[N];

void dfs(int u){
    if(u==n){
        for(int i=0;i<n;i++)
            printf("%s\n",g[i]);
        printf("\n");
    }
    for(int i=0;i<n;i++){
        if(!col[i]&&!dg[u+i]&&!udg[n-u+i]){
            g[u][i]='Q';
            col[i]=dg[u+i]=udg[n-u+i]=1;
            dfs(u+1);
            g[u][i]='.';
            col[i]=dg[u+i]=udg[n-u+i]=0;
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]='.';
    dfs(0);
    return 0;
}