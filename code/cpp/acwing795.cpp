#include<iostream>
using namespace std;
const int N=1e5+5;
int sum[N];
int main(){
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",sum+i);
        sum[i]+=sum[i-1];
    }
    while(m--){
        scanf("%d%d",&a,&b);
        printf("%d\n",sum[b]-sum[a-1]);
    }
    return 0;
}