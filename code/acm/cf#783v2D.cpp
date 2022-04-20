#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 5e5 + 5, INF = 0x3f3f3f3f;

int d;
int a[N], dp[N];
ll s[N];
vector<ll> alls;

struct node {
    int l, r;
    int val;
} tr[3][N << 2];

void push_up(int u) {
    tr[d][u].val = max(tr[d][u << 1].val, tr[d][u << 1 | 1].val);
}

void build(int u, int l, int r) {
    tr[d][u].l = l, tr[d][u].r = r;
    if (l == r) {
        tr[d][u].val = -INF;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void modify(int u, int x, int c) {
    if (tr[d][u].l == x && tr[d][u].r == x) {
        tr[d][u].val = max(tr[d][u].val, c);
        return;
    }
    int mid = tr[d][u].l + tr[d][u].r >> 1;
    if (x <= mid) modify(u << 1, x, c);
    else modify(u << 1 | 1, x, c);
    push_up(u);
}

int query(int u, int l, int r) {
    if (tr[d][u].l >= l && tr[d][u].r <= r)
        return tr[d][u].val;
    int mid = tr[d][u].l + tr[d][u].r >> 1;
    int res = -INF;
    if (l <= mid) res = max(res, query(u << 1, l, r));
    if (r > mid) res = max(res, query(u << 1 | 1, l, r));
    return res;
}

int find(ll x) {
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}

void init(int n) {
    alls.clear();
    memset(dp, -0x3f, sizeof(int) * (n + 1));
    dp[0] = 0;
}

void solve() {
    int n;
    scanf("%d", &n);
    init(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 0; i <= n; i++)
        alls.push_back(s[i]);
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (int i = 0; i < 3; i++) {
        d = i;
        build(1, 1, alls.size() + 1);
        modify(1, find(s[0]), 0);
    }

    for (int i = 1; i <= n; i++) {
        int w = find(s[i]);

        d = 0;
        dp[i] = max(dp[i], query(1, 1, w - 1) + i);

        d = 1;
        dp[i] = max(dp[i], query(1, w, w));

        d = 2;
        dp[i] = max(dp[i], query(1, w + 1, alls.size() + 1) - i);

        d = 0;
        modify(1, w, dp[i] - i);

        d = 1;
        modify(1, w, dp[i]);

        d = 2;
        modify(1, w, dp[i] + i);
    }
    printf("%d\n", dp[n]);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}