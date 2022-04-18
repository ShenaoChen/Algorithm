#include<iostream>
#include<queue>
#include<vector>

using namespace std;
const int N=1e5+5;
int n,m;
int h[N],e[N],ne[N],d[N],idx;
vector<int> ans;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
bool topSort(){
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(d[i]==0) q.push(i);
    while(!q.empty()){
        int t=q.front();
        ans.push_back(t);
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(--d[j]==0)
                q.push(j);
        }
    }
    return ans.size()==n;
}

int main(){
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        add(a,b);
        d[b]++;
    }
    if(!topSort())  printf("-1\n");
    else
        for(auto item:ans)
            printf("%d ",item);
    return 0;
}