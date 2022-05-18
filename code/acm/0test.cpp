#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

int primes[N], phi[N], cnt;
bool st[N];

ll euler(int n){
    ll ans = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0){
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1); 
        }
    }
    for (int i = 1; i <= n; i++)
        ans += phi[i];
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << euler(n) << endl;
    return 0;
}