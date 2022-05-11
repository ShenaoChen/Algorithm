#include <iostream>

using namespace std;

int a[210][210];

int fun(int i, int j, int n, int m) {
    int si = i, sj = j;
    int res = a[i][j];
    while (--i > 0 && --j > 0) res += a[i][j];
    i = si, j = sj;
    while (--i > 0 && ++j <= m) res += a[i][j];
    i = si, j = sj;
    while (++i <= n && --j > 0) res += a[i][j];
    i = si, j = sj;
    while (++i <= n && ++j <= m) res += a[i][j];
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        int mx = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                mx = max(mx, fun(i, j, n, m));
        cout << mx << endl;
    }
    return 0;
}