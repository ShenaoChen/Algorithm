#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int ans[N];
void init(int n){
    for(int i=1;i<=n;i++)
        a[i]=i;
}
int find(int x){
    if(a[x]!=x)
        a[x]=find(a[x]);
    return a[x];
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    a[x]=y;
    ans[a[x]]++;
}
int main(){
    int t,n,x,y,m;
    cin>>t;
    while(t--){
        cin>>n;
        memset(ans,0,sizeof(ans));
        init(n);
        m=0;
        while(n--){
            scanf("%d%d",&x,&y);
            merge(x,y);
        }
        for(int i=1;i<=n;i++){
            if(ans[a[i]]>m)
                m=ans[a[i]];
        }
        printf("%d\n",m);
    }
    return 0;
}