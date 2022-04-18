#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

struct Node{
    int l, r;
    ll sum, lazy;
}tr[N << 2];

int a[N];

void push_up(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void push_down(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    left.lazy += root.lazy, left.sum += (left.r - left.l + 1) * root.lazy;
    right.lazy += root.lazy, right.sum += (right.r - right.l + 1) * root.lazy;
    root.lazy = 0;
}

void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    if (l == r) {
        tr[u].sum = a[r];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void change(int u, int l, int r, int d) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].sum += (tr[u].r - tr[u].l + 1) * d;
        tr[u].lazy += d;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (tr[u].lazy) push_down(u);
    if (l <= mid) change(u << 1, l, r, d);
    if (r > mid) change(u << 1 | 1, l, r, d);
    push_up(u);
}

ll query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    if (tr[u].lazy) push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    ll sum = 0;
    if (l <= mid) sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    while (m--) {
        char op[2];
        int l, r;
        scanf("%s%d%d", op, &l, &r);
        if (*op == 'Q')
            printf("%lld\n", query(1, l, r));
        else {
            int d;
            scanf("%d", &d);
            change(1, l, r, d);
        }
    }
    return 0;
}