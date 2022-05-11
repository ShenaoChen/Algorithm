#include <iostream>
#include <cstring>

using namespace std;

const int N = 5000;

int h[N], e[N], ne[N], c[N], b[N], w[N], idx, ans;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        dfs(j);
        b[u] += b[j], w[u] += w[j];
    }
    if (c[u] == 0) b[u]++;
    else w[u]++;
    if (b[u] == w[u]) ans++;
}

void solve() {
    int n;
    string s;
    cin >> n;
    ans = 0;
    idx = 0;
    memset(h, -1, sizeof(int) * (n + 1));
    memset(b, 0, sizeof(int) * (n + 1));
    memset(w, 0, sizeof(int) * (n + 1));
    for (int i = 2; i <= n; i++) {
        int tmp;
        cin >> tmp;
        add(tmp, i);
    }
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') c[i + 1] = 0;
        else c[i + 1] = 1;
    }
    dfs(1);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}