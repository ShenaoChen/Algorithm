#include<iostream>

using namespace std;

typedef long long ll;

ll fac[20];

void solve(){
    int res = 0x3f3f3f3f;
    ll n;
    cin>>n;
    for(int i = 0; i < (1<<15); i++){
        ll tmp = 0;
        for(int j = 0; j < 15; j++)
            if(i >> j & 1)
                tmp += fac[j];
        if(n < tmp)
            break;
        res = min(res, __builtin_popcountll(i) + __builtin_popcountll(n - tmp));
    }
    cout<<res<<endl;
}

int main(){
    fac[0] = 1;
    for(int i  = 1; i <= 15; i++)
        fac[i] = fac[i - 1] * i;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
