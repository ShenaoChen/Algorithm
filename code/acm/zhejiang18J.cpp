#include<bits/stdc++.h>
using namespace std;
vector<int>e[3005];
int a[3005],d[3005],dp[3005][3005];
bool vis[3005];
void bfs(int n){
    queue<int>q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int i=0;i<e[tmp].size();i++){
            if(!vis[e[tmp][i]]){
                vis[e[tmp][i]]=1;
                d[e[tmp][i]]=d[tmp]+2;
                q.push(e[tmp][i]);
            }
        }
    }
}
int main(){
    int n,m,t,x,y;
    cin>>n>>m>>t;
    for(int i=2;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        if(x!=y){
            e[x].push_back(y);
            e[y].push_back(x);
        }
    }
    bfs(n); 
    for(int i=2;i<=n;i++){
        for(int j=1;j<=t;j++){
            if(j<d[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-d[i]]+a[i]);
        }
    }
    for(int i=1;i<=t;i++)
        printf("%d ",dp[n][i]);
    return 0;
}