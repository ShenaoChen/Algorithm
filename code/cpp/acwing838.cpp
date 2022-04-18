#include<iostream>
#include<queue>

using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int>> q;
    int n,m,tmp;
    cin>>n>>m;
    while(n--){
        scanf("%d",&tmp);
        q.push(tmp);
    }
    while(m--){
        printf("%d ",q.top());
        q.pop();
    }
    return 0;
}