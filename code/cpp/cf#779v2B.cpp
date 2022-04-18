#include <iostream>

using namespace std;

const int N = 1005;
const int mod = 998244353;
int fact[N];

int main() {
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = 1ll * fact[i - 1] * i % mod;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n & 1)
            cout << 0 << endl;
        else
            cout << 1ll * fact[n / 2] * fact[n / 2] % mod << endl;
    } 
    return 0;
}