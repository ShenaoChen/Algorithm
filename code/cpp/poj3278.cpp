#include<iostream>
#include<cstring>
#include<queue>
#include<stdio.h>
using namespace std;
const int MAX=1e5+5;
bool vis[MAX];
queue<pair<int ,int> >q;
int bfs(int n,int k){
    if(n==k)
        return 0;
    pair<int ,int > tmp;
    int t;
    q.push(pair<int,int>(n,0));
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        for(int i=0;i<3;i++){
            if(i==0)
                t=tmp.first-1;
            if(i==1)
                t=tmp.first+1;
            if(i==2)
                t=tmp.first*2;
            if(t<0||t>MAX||vis[t])
                continue;
            vis[t]=1;
            if(t==k)
                return tmp.second+1;
            else 
                q.push(pair<int ,int >(t,tmp.second+1));
        }      
    }
    return -1;
}
int main(){
    int n,k,ans;
    while(~scanf("%d%d",&n,&k)){
        memset(vis,0,sizeof(vis));
        while(!q.empty())
            q.pop();
        cout<<bfs(n,k)<<endl;
    }
    return 0;
}