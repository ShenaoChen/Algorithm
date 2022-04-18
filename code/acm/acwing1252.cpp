#include <iostream>

using namespace std;

const int N = 10010;

int n, m, c;
int s[N], v[N], w[N], dp[N];

int find(int x) {
    if (s[x] != x) s[x] = find(s[x]);
    return s[x];
}

int main() {
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        s[i] = i;
        cin >> v[i] >> w[i];
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        a = find(a), b = find(b);
        if (a == b) continue;
        v[b] += v[a];
        w[b] += w[a];
        s[a] = b;
    }
    for (int i = 1; i <= n; i++)
        if (s[i] == i)
            for (int j = c; j >= v[i]; j--)
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[c] << endl;
    return 0;
}