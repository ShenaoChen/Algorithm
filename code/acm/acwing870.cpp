#include<iostream>
#include<unordered_map>

using namespace std;

typedef long long ll;

const int mod = 1e9+7;

int n, x;
long long ans;
unordered_map<int, int> primes;

int main(){
    cin>>n;
    while(n -- ){
        cin>>x;
        for(int i = 2; i <= x / i; i ++ )
            while(x % i == 0){
                x /= i;
                primes[i] ++;
            }
        if(x > 1)
            primes[x] ++;
    }

    for(auto prime : primes)
        ans = ans * (1 + prime.second) % mod;

    cout<<ans<<endl;

    return 0;
}