#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;
const int inf = 0x3f3f3f3f;

int sum[N], dp[N][N];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        int tmp;
        cin>>tmp;
        sum[i] = sum[i - 1] + tmp;
    }
    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= n; i++) dp[i][i] = 0;
    for(int len = 1; len <= n; len++){
        for(int i = 1; i <= n - len + 1; i++){
            int j = i + len - 1;
            for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
        }
    }
    cout<< dp[1][n] <<endl;
    return 0;
}