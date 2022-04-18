#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct node{
    string s;
    int r;
    node(string s,int r){
        this->s=s;
        this->r=r;
    }
};
string bfs(int k){
    int r=1,m=10%k;
    string s="1";
    node tmp(s,r);
    queue<node>q;
    q.push(tmp);
    while(!q.empty()){
        tmp=q.front();
        q.pop();
        if(((tmp.r*m)%k+1)%k!=0)
            q.push(node(tmp.s+"1",((tmp.r*m)%k+1)%k));
        else
            return tmp.s+"1";
        if((tmp.r*m)%k!=0)
            q.push(node(tmp.s+"0",(tmp.r*m)%k));
        else
            return tmp.s+"0";
    }
    return s;
}
int main(){
    int a;
    int n;
    //while(scanf("%d",&n)&&n)
    for(int n=1;n<=200;n++){
        cout<<"\""<<bfs(n)<<"\""<<','<<endl;
    }
    return 0;
}