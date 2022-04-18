#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll x,y,z,ans;
    int t;
    cin>>t;
    while(t--){
        scanf("%lld%lld%lld",&x,&y,&z);
        if(x+y==z)
            ans=z+1;
        else{
            ans=x+y-z;
            if(ans<=max(x,z))
                ans=-1;
        }
        printf("%lld\n",ans);
    }   
    return 0;
}