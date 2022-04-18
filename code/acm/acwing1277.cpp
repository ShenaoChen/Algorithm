#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

struct Node {
    int l, r;
    ll sum, mul, add;
} tr[N << 2];

int a[N];
int n, m, p;

void push_up(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void push_down(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    left.sum = (left.sum * root.mul + (left.r - left.l + 1) * root.add) % p;
    right.sum = (right.sum * root.mul + (right.r - right.l + 1) * root.add) % p;
    left.mul = left.mul * root.mul % p, right.mul = right.mul * root.mul % p;
    left.add = (left.add * root.mul + root.add) % p;
    right.add = (right.add * root.mul + root.add) % p;
    root.mul = 1, root.add = 0;
}

void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    tr[u].mul = 1, tr[u].add = 0;
    if (l == r) {
        tr[u].sum = a[r];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void change(int u, int l, int r, int c, int d) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum = tr[u].sum * c + (tr[u].r - tr[u].l + 1) * d;
        tr[u].mul *= c;
        tr[u].add = tr[u].add * c + d;
        return;
    }
    push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) change(u << 1, l, r, c, d);
    if (r > mid) change(u << 1 | 1, l, r, c, d);
    push_up(u);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum % p;
    push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    ll res = 0;
    if (l <= mid) res += query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);
    return res % p;
}

int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    cin >> m;
    build(1, 1, n);
    while (m--) {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        if (op == 3) {
            printf("%d\n", query(1, x, y));
            continue;
        }
        int c;
        scanf("%d", &c);
        if (op == 1) change(1, x, y, c, 0);
        else change(1, x, y, 1, c);
    }
    return 0;
}