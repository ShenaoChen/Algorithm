#include<iostream>
#include<unordered_map>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;


int main(){
    ll ans = 0;
    int n, x;
    unordered_map<int, int> primes;
    
    cin>>n;
    while(n -- ){
        cin>>x;
        for(int i = 2; i <= x / i; i ++ ){
            while(x % i == 0){
                primes[i] ++;
                x /= i;
            }
        }
        if(x > 1)
            primes[x] ++;
    }

    for(auto prime : primes){
        int a = prime.first, b = prime.second;
        ll t = 1;
        while(b -- )
            t =(t * a + 1) % mod;
        ans = ans * t % mod; 
    }
    cout<<ans<<endl;
    return 0;
}