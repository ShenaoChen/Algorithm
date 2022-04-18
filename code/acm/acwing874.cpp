#include<iostream>
#include<cstring>

using namespace std;

const int N = 1e6 + 5;

typedef long long ll;

int primes[N], phi[N], cnt;
bool st[N];

void euler(int n){
    //memset(phi, 1, sizeof phi);
    phi[1] = 1;
    for(int i = 2; i <= n; i ++ ){
        if(!st[i]){
            primes[cnt ++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; primes[j] <= n / i; j ++ ){
            int t = primes[j] * i;
            st[t] = true;
            if(i % primes[j] == 0){
                phi[t] = phi[i] * primes[j];
                break;
            }
            phi[t] = phi[i] * (primes[j] - 1);
        }
    }
}

int main(){
    int n;
    ll ans = 0;
    cin>>n;

    euler(n);

    for(int i =1; i <= n; i ++ )
        ans += phi[i];
    
    cout<< ans <<endl;
    return 0;
}
