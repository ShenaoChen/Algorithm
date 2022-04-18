#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
const int p = 998244353;

ll ans = 1;
int fact[N], infact[N], ni[N];
vector<int> g[N];

int power(ll a, ll b) {
    ll c = 1;
    while (b) {
        if (b & 1)
            c = c * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return c;
}

int dfs(int u, int fa) {
    int tmp = 0;
    for (auto v : g[u]) {
        if (v == fa) continue;
        tmp += dfs(v, u);
    }
    int n = g[u].size() - 1 - tmp;
    if (fa == -1) n++;
    if (n & 1) ans = ans * n % p * fact[n - 1] % p * ni[n / 2] % p * infact[n / 2] % p;
    else ans = ans * fact[n] % p * ni[n / 2] % p * infact[n / 2] % p;
    return n & 1;
}

int main() {
    fact[0] = 1, infact[0] = 1, ni[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = 1ll * fact[i - 1] * i % p;
    for (int i = 1; i < N; i++) infact[i] = 1ll * infact[i - 1] * power(i, p - 2) % p;
    for (int i = 1; i < N; i++) ni[i] = 1ll * ni[i - 1] * 499122177 % p;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}