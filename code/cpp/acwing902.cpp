#include <iostream>

using namespace std;

const int N = 1010;

char a[N], b[N];
int dp[N][N];

int main(){
    int n, m;
    scanf("%d%s", &n, a + 1);
    scanf("%d%s", &m, b + 1);
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int i = 0; i <= m; i++) dp[0][i] = i;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if(a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i -1][j - 1]);
            else dp[i][j] = min(dp[i][j], dp[i -1][j - 1] + 1);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}