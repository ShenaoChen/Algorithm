#include <iostream>

using namespace std;

const int N = 5e5 + 5;

struct Node{
    int l, r, tmax;
    int lmax, rmax, sum;
}tr[N << 2];

int a[N];

void push_up(Node &root, Node &left, Node &right) {
    root.sum = left.sum + right.sum;
    root.lmax = max(left.lmax, left.sum + right.lmax);
    root.rmax = max(right.rmax, left.rmax + right.sum);
    root.tmax = max(left.tmax, right.tmax);
    root.tmax = max(root.tmax, left.rmax + right.lmax);
}

void push_up(int u) {
    push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if (l == r) {
        int t = a[r];
        tr[u] = {l, r, t, t, t, t};
        return;
    }
    tr[u].l = l, tr[u].r = r;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void change(int u, int x, int y) {
    if (tr[u].l == x && tr[u].r == x) {
        tr[u] = {x, x, y, y, y, y};
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid) change(u << 1, x, y);
    else change(u << 1 | 1, x, y);
    push_up(u);
}

Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid) return query(u << 1, l, r);
    else if (l > mid) return query(u << 1 | 1, l, r);
    else {
        Node res;
        auto left = query(u << 1, l, r);
        auto right = query(u << 1 | 1, l, r);
        push_up(res, left, right);
        return res;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    while (m--) {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if (k == 2)
            change(1, x, y);
        else {
            if (x > y) swap(x, y);
            cout << query(1, x, y).tmax << endl;
        }
    }
    return 0;
}