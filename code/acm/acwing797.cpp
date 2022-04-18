#include<iostream>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int main(){
    int n,m,tmp,l,r,c;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&tmp);
        b[i]+=tmp;
        b[i+1]-=tmp;
    }
    while(m--){
        scanf("%d%d%d",&l,&r,&c);
        b[l]+=c;
        b[r+1]-=c;
    }
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+b[i];
        printf("%d ",a[i]);
    }
    return 0;
}