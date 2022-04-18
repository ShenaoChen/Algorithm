#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t,n,x;
    ll ans;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        ans=0;
        x=(n-1)/3+1;
        if(x%2==0)
            x++;
        ans+=(n-x)/2+1;
        x=n/2+1;
        ans+=n-x+1;
        printf("%lld\n",ans);
    }
    return 0;
}