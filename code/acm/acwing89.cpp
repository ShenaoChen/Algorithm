#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll a,ll b,ll p){
    ll c=1%p;
    while(b){
        if(b&1)
            c=c*a%p;
        a=a*a%p;
        b>>=1;
    }
    return c;
}
int main(){
    ll a,b,p;
    cin>>a>>b>>p;
    cout<<pow(a,b,p)<<endl;
    return 0;
}