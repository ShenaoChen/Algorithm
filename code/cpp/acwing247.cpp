#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1010;

struct Node {
    int l, r;
    int cnt;
    double len;
} tr[N << 3];

struct Edge {
    double x, y1, y2;
    int k;
    bool operator<(const Edge &e)const {
        return x < e.x;
    }
} edges[N << 1];

vector<double> alls;

int find(double x) {
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin();
}

void push_up(int u) {
    if (tr[u].cnt > 0)
        tr[u].len = alls[tr[u].r + 1] - alls[tr[u].l];
    else if (tr[u].l == tr[u].r)
        tr[u].len = 0;
    else
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
}

void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    if (l != r) {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }
}

void change(int u, int l, int r, int k) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].cnt += k;
        push_up(u);
    }
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) change(u << 1, l, r, k);
        if (r > mid) change(u << 1 | 1, l, r, k);
        push_up(u);
    }
}

int main() {
    int n, T = 1;
    while (cin >> n, n) {
        double res = 0;
        double x1, x2, y1, y2;
        for (int i = 0, j = 0; i < n; i++) {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            edges[j++] = {x1, y1, y2, 1};
            edges[j++] = {x2, y1, y2, -1};
            alls.push_back(y1);
            alls.push_back(y2);
        }
        sort(edges, edges + 2 * n);
        sort(alls.begin(), alls.end());
        alls.erase(unique(alls.begin(), alls.end()), alls.end());
        build(1, 0, alls.size() - 2);
        for (int i = 0; i < 2 * n; i++) {
            if (i > 0) res += tr[1].len * (edges[i].x - edges[i - 1].x);
            change(1, find(edges[i].y1), find(edges[i].y2) - 1, edges[i].k);
        }
        printf("Test case #%d\n", T++);
        printf("Total explored area: %.2lf\n\n", res);
    }
    return 0;
}