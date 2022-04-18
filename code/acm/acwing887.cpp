#include <iostream>

using namespace std;

typedef long long ll;

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

int C(int a, int b, int p) {
    if (b > a) return 0;
    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = 1ll * res * j % p;
        res = 1ll * res * power(i, p - 2, p) % p;
    }
    return res;
}

int lucas(ll a, ll b, int p) {
    if (a < p && b < p) return C(a, b, p);
    return 1ll * C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main() {
    int n;
    ll a, b;
    int p;
    cin >> n;
    while (n--) {
        cin >> a >> b >> p;
        cout << lucas(a, b, p) << endl;
    }
    return 0;
}