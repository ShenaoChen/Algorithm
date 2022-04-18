#include <iostream>

using namespace std;

typedef long long ll;

const int N = 5010;

ll sum[N], w[N], dp[N][N];

int main(){
    int n, m, k, cnt = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        sum[i] = sum[i - 1] + tmp;
    }
    for(int i = m; i <= n; i++)
        w[++cnt] = sum[i] - sum[i - m];
    for(int i = 1; i <= cnt; i++)
        for(int j = 1; j <= k; j++)
            if(i <= m) dp[i][j] = max(dp[i - 1][j], w[i]);
            else dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + w[i]);
    cout << dp[cnt][k] << endl;
    return 0;
}