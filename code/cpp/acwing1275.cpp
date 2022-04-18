#include <iostream>

using namespace std;

const int N = 2e5 + 5;

typedef long long ll;

struct Node{
    int l, r;
    int mx;
}tr[N << 2];

int a[N];

void pushup(int u) {
    tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {l, r, 0};
    else {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }
}

void change(int u, int x, int d) {
    if(tr[u].l == x && tr[u].r == x) tr[u].mx += d;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) change(u << 1, x, d);
        else change (u << 1 | 1, x, d);
        pushup(u);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].mx;
    int mid = tr[u].l + tr[u].r >> 1;
    int mx = 0;
    if (l <= mid) mx = max(mx, query(u << 1, l, r));
    if (r > mid) mx = max(mx, query(u << 1 | 1, l, r));
    return mx;
}

int main() {
    int n, p;
    cin >> n >> p;
    build(1, 1, n);
    int x, cnt = 0, last = 0;
    char op[2];
    for (int i = 1; i <= n; i++) {
        scanf("%s%d", op, &x);
        if (*op == 'Q') {
            last = query(1, cnt - x + 1, cnt);
            printf("%d\n", last);
        }
        else {
            cnt++;
            change(1, cnt, ((ll)x + last) % p);
        }
    }
    return 0;
}