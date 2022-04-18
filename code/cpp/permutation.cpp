#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
    int t,n,cnt;
    cin>>t;
    while(t--){
        cin>>n;
        cnt=1;
        for(int i=1;i<=n;i+=2)
            a[i]=cnt++;
        for(int i=2;i<=n;i+=2)
            a[i]=cnt++;
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}