#include <iostream>
#include <cstring>

using namespace std;

const int N = 2005;

char a[N][N];

void solve() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == '1') {
                cnt++;
            }
        }
    }
    int tmp = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (a[(i + j) % n + 1][j] == '1')
                tmp++;
        }
        mx = max(mx, tmp);
        tmp = 0;
    }
    int ans = n + cnt - 2 * mx;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}