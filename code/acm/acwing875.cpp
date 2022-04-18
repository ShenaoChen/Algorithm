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
    int n;
    int a, b, c;
    cin>>n;
    while(n -- ){
        cin>>a>>b>>c;
        cout<<pow(a, b, c);
    }
    return 0;
}