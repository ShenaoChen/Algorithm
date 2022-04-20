#include <iostream>

using namespace std;

typedef long long ll;

const int N = 5010;

int a[N];

int main() {
    int n;
    ll res = 1e17;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        ll tmp = 0, last = 0;
        for (int j = i - 1; j > 0; j--) {
            ll k = last / a[j] + 1;
            last = k * a[j];
            tmp += k;
        }
        last = 0;
        for (int j = i + 1; j <= n; j++) {
            ll k = last / a[j] + 1;
            last = k * a[j];
            tmp += k;
        }
        res = min(res, tmp);
    }
    cout << res << endl;
    return 0;
}