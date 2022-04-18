#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int c, int n) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main() {
    int n, m, tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        add(i, tmp, n);
        add(i + 1, -tmp, n);
    }
    char op[2];
    while (m--) {
        scanf("%s", op);
        if (*op == 'Q') {
            int x;
            scanf("%d", &x);
            cout << query(x) << endl;
        }
        else {
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            add(l, d, n);
            add(r + 1, -d, n);
        }
    }
    return 0;
}