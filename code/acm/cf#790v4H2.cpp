#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int a[N], tr[N], n;

int lowbit(int x) {
    return x & -x;
}

void add(int x) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i]++;
}

int sum(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll ans = 0;
        cin >> n;
        memset(tr, 0, sizeof(int) * (n + 1));
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = n - 1; i >= 0; i--) {
            ans += sum(a[i]);
            add(a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}