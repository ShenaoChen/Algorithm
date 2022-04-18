#include<iostream>

using namespace std;

typedef long long ll;

ll pow(ll a, ll b, ll p){
    ll c = 1 % p;
    while(b){
        if(b & 1)
            c = c * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return c;
}

int main(){
    int n, a, b;
    cin>>n;
    while(b -- ){
        cin>>a>>b;
        if(a % b == 0) puts("impossible");
        else printf("%d\n",pow(a, b - 2, b));
    }
    return 0;
}