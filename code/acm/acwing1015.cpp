#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int T;
int n, m;
int w[N][N];
int f[N][N];

int main()
{
    cin >> T;
    while (T--) {
        memset(w, 0, sizeof w);
        memset(f, 0, sizeof f);
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> w[i][j];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = max(f[i][j - 1], f[i - 1][j]) + w[i][j];
            }
        }

        cout << f[n][m] << endl;
    }
    return 0;
}