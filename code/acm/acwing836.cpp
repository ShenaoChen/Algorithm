#include<iostream>

using namespace std;

const int N=1e5+5;
int s[N],n,m;

int find(int x){
    if(s[x]!=x)
        s[x]=find(s[x]);
    return s[x];
}

int main(){
    char op;
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++) s[i]=i;
    while(m--){
        scanf("%c %d%d",&op,&a,&b);
        if(op=='M') s[find(a)]=s[find(b)];
        else printf(s[find(a)]==s[find(b)]?"Yes\n":"No\n");
    }
    return 0;
}