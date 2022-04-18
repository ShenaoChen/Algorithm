#include <iostream>

using namespace std;

typedef long long ll;

const int N = 3e5 + 5;

int n, k;
ll a[N], tr1[N], tr2[N];

ll lowbit(ll x) {
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
    cin >> n >> k;
    ll res = 0;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    for (int i = n; i >= 1; i--) {
        if (sum(i) >= a[i]) continue;
        int l = max(1, i - k + 1);
        ll tmp = a[i] - sum(i);
        ll d = tmp / (i - l + 1) + (tmp % (i - l + 1) == 0 ? 0 : 1);
        res += d;
        add(tr1, l, d), add(tr2, l, 1ll * l * d);
    }
    cout << res << endl;
    return 0;
}