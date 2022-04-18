#include <iostream>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int x[N];
ll sum[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        for (int i = 1; i <= n;i++) {
            scanf("%d", &x[i]);
            sum[i] = sum[i - 1] + x[i];
        }
        ll res = 1e18;
        for (int i = 0; i <= n; i++)
            res = min(res, 1ll * (a + b) * x[i] + 1ll * (sum[n] - sum[i] - 1ll * (n - i) * x[i]) * b);
        cout << res << endl;
    }
    return 0;
}