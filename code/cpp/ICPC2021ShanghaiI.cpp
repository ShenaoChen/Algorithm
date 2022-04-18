#include <iostream>

using namespace std;

typedef long long ll;

const int N = 210, M = N * 13;

int t[N], v[N];
ll dp[2][M][N];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> t[i];
    for (int i = 0; i < N; i++)
        for (int j = 1; j < M; j++)
            dp[0][j][i] = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w < M; w++) {
            for (int j = 0; j <= k; j++) {
                int x = i & 1;
                dp[x][w][j] = dp[x ^ 1][w][j];
                if (w - t[i] >= 0)
                    dp[x][w][j] = max(dp[x][w][j], dp[x ^ 1][w - t[i]][j] + v[i]);
                if (w + t[i] < M)
                    dp[x][w][j] = max(dp[x][w][j], dp[x ^ 1][w + t[i]][j] + v[i]);
                if (w - 2 * t[i] >= 0 && j)
                    dp[x][w][j] = max(dp[x][w][j], dp[x ^ 1][w - 2 * t[i]][j - 1] + v[i]);
                if (w + 2 * t[i] < M && j)
                    dp[x][w][j] = max(dp[x][w][j], dp[x ^ 1][w + 2 *t[i]][j - 1] + v[i]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++)
        ans = max(ans, dp[n & 1][0][i]);
    cout << ans << endl;
    return 0;
}