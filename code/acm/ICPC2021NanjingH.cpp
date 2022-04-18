#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

ll f[N], sum[N];
int a[N], t[N];
vector<int> g[N];

void maximum(ll &x, ll y) {
    if (x < y)
        x = y;
}

void dfs(int u, int fa) {
    int pos;
    ll max1 = -1, max2 = -1;
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        int val = sum[v] + a[v] - f[v];
        if (val > max1) 
            max2 = max1, max1 = val, pos = v;
        else 
            maximum(max2, val);
        sum[u] += f[v]; 
        maximum(f[u], a[v]);
    }
    for (int v : g[u]) {
        if (v != fa && t[v] == 3)
            maximum(f[u], a[v] + (v == pos ? max2 : max1));
    }
    f[u] += sum[u];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, u, v;
        //scanf("%d", &n);
        cin >> n;
        memset(f + 1, 0, 8 * n);
        memset(sum + 1, 0, 8 * n);
        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= n; i++) //scanf("%d", &a[i]);
            cin >> a[i];
        for (int i = 1; i <= n; i++) //scanf("%d", &t[i]);
            cin >> t[i];
        for (int i = 1; i < n; i++) {
            //scanf("%d%d", &u, &v);
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, -1);
        //printf("%lld\n", f[1] + a[1]);
        cout << a[1] + f[1] << "\n";
    }
    return 0;
}