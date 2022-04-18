#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int a,b;
    vector<int>path;
    node(int a,int b,vector<int>path){
        this->a=a;
        this->b=b;
        this->path=path;
    }
};
bool vis[105][105];
string opt[7]={"0","FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};
void print(node x){
    cout<<x.path.size()<<endl;
    for(int i=0;i<x.path.size();i++){
        cout<<opt[x.path[i]]<<endl;
    }
}
void bfs(int A,int B,int C){
    if(C==0){
        cout<<0<<endl;
        return ;
    }
    queue<node>q;
    vector<int>v;
    q.push(node(0,0,v));
    while(!q.empty()){
        node t=q.front();
        q.pop();
        if(vis[t.a][t.b])
            continue;
        vis[t.a][t.b]=1;
        //vis[tmp.a][tmp.b]=1;
        if(t.a!=A){
            node tmp=t;
            tmp.path.push_back(1);
            tmp.a=A;
            if(A==C){
                print(tmp);
                return ;
            }
            else{
               // vis[tmp.a][tmp.b]=1;
                q.push(tmp);
            }
        }
        if(t.b!=B){
            node tmp=t;
            tmp.path.push_back(2);
            tmp.b=B;
            if(B==C){
                print(tmp);
                return ;
            }
            else{
               // vis[tmp.a][tmp.b]=1;
                q.push(tmp);
            }
        }
        if(t.a!=0){
            node tmp=t;
            tmp.path.push_back(3);
            tmp.a=0;
            if(0==C){
                print(tmp);
                return ;
            }
            else{
                //vis[tmp.a][tmp.b]=1;
                q.push(tmp);
            }
        }
        if(t.b!=0){
            node tmp=t;
            tmp.path.push_back(4);
            tmp.b=0;
            if(0==C){
                print(tmp);
                return ;
            }
            else{
                //vis[tmp.a][tmp.b]=1;
                q.push(tmp);
            }
        }
        if(t.a!=0&&t.b!=B){
            node tmp=t;
            tmp.path.push_back(5);
            tmp.b+=tmp.a;
            tmp.a=max(0,tmp.b-B);
            tmp.b=min(tmp.b,B);
            if(tmp.a==C||tmp.b==C){
                print(tmp);
                return ;
            }
            else{
                //vis[tmp.a][tmp.b]=1;
                q.push(tmp);
            }
        }
        if(t.b!=0&&t.a!=A){
            node tmp=t;
            tmp.path.push_back(6);
            tmp.a+=tmp.b;
            tmp.b=max(0,tmp.a-A);
            tmp.a=min(tmp.a,A);
            if(tmp.a==C||tmp.b==C){
                print(tmp);
                return ;
            }
            else{
                //vis[tmp.a][tmp.b]=1;
                q.push(tmp);
            }
        }
    }
    cout<<"impossible"<<endl;
}
int main(){
    int A,B,C;
    cin>>A>>B>>C;
    bfs(A,B,C);
    return 0;
}