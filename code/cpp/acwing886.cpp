#include <iostream>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int fact[N], infact[N];

int power(int a, int b, int p) {
    int c = 1 % p;
    while (b) {
        if (b & 1)
            c = 1ll * c * a % p;
        a = 1ll * a * a % p;
        b >>= 1;
    }
    return c;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
    for (int i = 0; i < N; i++) infact[i] = power(fact[i], mod - 2, mod);
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << 1ll * fact[a] * infact[b] % mod * infact[a - b] % mod << endl;
    }
    return 0;
}