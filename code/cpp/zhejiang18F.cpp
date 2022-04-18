#define inf 0x7f7f7f7f
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    if(n>m) 
        printf("%lld\n",n-m);
    else{
        ll ans=inf;
        for(int l=1,r;l<=n;l=r+1){
            r=min(n,(m-1)/((m-1)/l));
            ans=min(ans,(m-1)/l*l);
        }
        printf("%lld\n",ans+n-m);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}