#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, tmp;
        vector<ll> a;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            a.push_back(tmp);
        }
        sort(a.begin(), a.end(), greater<ll>());
        for (int i = 1; i < n; i++) a[i] += a[i - 1];
        while (m--) {
            int x;
            cin >> x;
            tmp = lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
            if (tmp > n) cout << -1 << endl;
            else cout << tmp << endl;
        }
    }
    return 0;
}