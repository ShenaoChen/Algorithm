#include <iostream>

using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

struct Node {
    int l, r;
    ll sum, d;
} tr[N << 2];

ll a[N], b[N];

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void push_up(Node &root, Node &left, Node &right) {
    root.sum = left.sum + right.sum;
    root.d = gcd(left.d, right.d);
}

void push_up(int u) {
    push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    if (l == r) {
        tr[u].sum = b[r];
        tr[u].d = b[r];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);    
}

void change(int u, int x, ll d) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u].sum += d;
        tr[u].d +=d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) change(u << 1, x, d);
    else change(u << 1 | 1, x, d);
    push_up(u);
}

Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid) return query(u << 1, l, r);
    if (l > mid) return query(u << 1 | 1, l, r);
    Node res;
    auto left = query(u << 1, l, r);
    auto right = query(u << 1 | 1, l, r);
    push_up(res, left, right);
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - a[i - 1];
    build(1, 1, n);
    while (m--) {
        char op[2];
        int l, r;
        scanf("%s%d%d", op, &l, &r);
        if (*op == 'Q') {
            Node left = query(1, 1, l);
            Node right = {0, 0, 0, 0};
            if (l < n)
                right = query(1, l + 1, r);
            printf("%lld\n", abs(gcd(left.sum, right.d)));
        }
        else {
            ll d;
            scanf("%lld", &d);
            change(1, l, d);
            if (r < n)
                change(1, r + 1, -d);
        }
    }
    return 0;
}