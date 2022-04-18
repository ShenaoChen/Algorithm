#include <iostream>

using namespace std;

typedef long long ll;

const int N = 30;

int a[N], b[N];

void solve() {
    int n;
    ll res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 1; i < n; i++) {
        if (abs(b[i] - a[i - 1])  + abs(a[i] - b[i - 1]) < abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]))
            swap(a[i], b[i]);
        res += abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]);
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}