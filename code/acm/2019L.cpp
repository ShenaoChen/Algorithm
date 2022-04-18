#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e9+7;
ll f(ll x){
    ll ans=1;
    int tmp;
    while(x){
        tmp=x%10;
        x/=10;
        ans=ans*tmp%M;
    }
    return ans;
}
int main(){
    int t;
    ll l,r,ans;
    cin>>t;
    while(t--){
        ans=1;
        scanf("%lld%lld",&l,&r);
        if(r-l>=9){
            printf("0\n");
            continue;
        }
        for(ll i=l;i<=r;i++)
            ans=ans*f(i)%M;
        printf("%lld\n",ans);
    }
    return 0;
} 