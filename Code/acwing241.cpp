#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, a[N], tr[N], gre[N], low[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int c) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int sum(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main() {
    ll res1 = 0, res2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(a[i], 1);
        gre[i] = sum(n) - sum(a[i]);
        low[i] = sum(a[i] - 1) - sum(0);
    }
    memset(tr, 0, sizeof tr);
    for (int i = n; i > 0; i--) {
        add(a[i], 1);
        res1 += 1ll * gre[i] * (sum(n) - sum(a[i]));
        res2 += 1ll * low[i] * (sum(a[i] - 1) - sum(0));
    }
    cout << res1 << ' ' << res2 << endl;
    return 0;
}