#include<iostream>
#include<queue>
using namespace std;
struct node{
    int x,d;
    node(int x,int d){
        this->x=x;
        this->d=d;
    }
};
bool isPrime(int n){
    if(n==0||n==1)
        return 0;
    for(int i=2;i<=n/i;i++)
        if(n%i==0)
            return 0;
    return 1;
}
void bfs(int n,int m){
    bool vis[10000]={0};
    queue<node>q;
    q.push(node(n,0));
    while(!q.empty()){
        node tmp=q.front();
        q.pop();
        if(tmp.x==m){
            cout<<tmp.d<<endl;
            return;
        }
        for(int i=1;i<=9;i+=2){
            if(isPrime(tmp.x/10*10+i)&&!vis[tmp.x/10*10+i]){
                vis[tmp.x/10*10+i]=1;
                if(tmp.x/10*10+i!=m)
                    q.push(node(tmp.x/10*10+i,tmp.d+1));
                else{
                    cout<<tmp.d+1<<endl;
                    return;
                }
            }
        }
        for(int i=0;i<=9;i++){
            if(isPrime(tmp.x/100*100+10*i+tmp.x%10)&&!vis[tmp.x/100*100+10*i+tmp.x%10]){
                vis[tmp.x/100*100+10*i+tmp.x%10]=1;
                if(tmp.x/100*100+10*i+tmp.x%10!=m)
                    q.push(node(tmp.x/100*100+10*i+tmp.x%10,tmp.d+1));
                else{
                    cout<<tmp.d+1<<endl;
                    return;
                }
            }
        }
        for(int i=0;i<=9;i++){
            if(isPrime(tmp.x/1000*1000+100*i+tmp.x%100)&&!vis[tmp.x/1000*1000+100*i+tmp.x%100]){   
                vis[tmp.x/1000*1000+100*i+tmp.x%100]=1;
                if(tmp.x/1000*1000+100*i+tmp.x%100!=m)
                    q.push(node(tmp.x/1000*1000+100*i+tmp.x%100,tmp.d+1));
                else{
                    cout<<tmp.d+1<<endl;
                    return;
                }
            }
        }
        for(int i=1;i<=9;i++){
            if(isPrime(1000*i+tmp.x%1000)&&!vis[1000*i+tmp.x%1000]){
                vis[1000*i+tmp.x%1000]=1;
                if(1000*i+tmp.x%1000!=m)
                    q.push(node(1000*i+tmp.x%1000,tmp.d+1));
                else{
                    cout<<tmp.d+1<<endl;
                    return ;
                }
            }
        }
    }
}
int main(){
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        bfs(n,m);
    }
    return 0;
}