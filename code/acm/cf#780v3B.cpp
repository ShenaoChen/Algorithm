#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1) {
        cout << (a[0] == 1 ? "YES" : "NO") << endl;
        return;
    }
    sort(a, a + n);
    if (a[n - 1] - a[n - 2] > 1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}