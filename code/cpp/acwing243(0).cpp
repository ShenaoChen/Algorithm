#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int n, m;
int a[N];
ll tr1[N], tr2[N];

int lowbit(int x) {
    return x & -x;
}

void add(ll tr[], int x, ll d) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += d;
}

ll query(ll tr[], int x) {
    ll res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

ll sum(int x) {
    return query(tr1, x) * (x + 1) - query(tr2, x);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        add(tr1, i, a[i] - a[i - 1]);
        add(tr2, i, 1ll * i * (a[i] - a[i - 1]));
    }
    while (m--) {
        char op[2];
        scanf("%s", op);
        if (*op == 'Q') {
            int l, r;
            cin >> l >> r;
            cout << sum(r) - sum(l- 1) << endl;;
        }
        else {
            int l, r, d;
            cin >> l >> r >> d;
            add(tr1, l, d), add(tr2, l, l * d);
            add(tr1, r + 1, -d), add(tr2, r + 1, (r + 1) * -d);
        }
    }
    return 0;
}