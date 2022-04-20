#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int a[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n, greater<int>());
    ll pos  = a[0] + 1;
    for (int i = 1; i < n; i++) 
        pos += a[i - 1] + 1;
    if (pos <= m) cout << " YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}