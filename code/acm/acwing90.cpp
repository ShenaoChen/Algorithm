#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mul(ll a,ll b,ll p){
    ll c=0;
    while(b){
        if(b&1)
            c=(c+a)%p;
        a=a*2%p;
        b>>=1;
    }
    return c;
}
int main(){
    ll a,b,p;
    cin>>a>>b>>p;
    cout<<mul(a,b,p)<<endl;
    return 0;
}