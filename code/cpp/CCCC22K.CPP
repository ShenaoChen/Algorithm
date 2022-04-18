#include<iostream>
#include<cstring>

using namespace std;

const int inf = 0x3f3f3f3f;

int dp[105][105];
int sum[105];

int main(){
    int n, tmp;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>tmp;
        sum[i] = sum[i - 1] + tmp;
    }
    memset(dp, inf, sizeof dp);
    for(int i = 0; i <= n; i++)
        dp[i][i] = 0;
    for(int len = 1; len < n; len++){
        for(int i = 1; i <= n - len; i++){
            int j = i + len;
            for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}