#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 12, M = 1 << N;

ll dp[N][M];
bool st[M];

int main(){
    int n, m;
    while(cin >> n >> m, n || m){
        for(int i = 0; i < 1<<n; i++){
            st[i] = true;
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i >> j & 1){
                    if(cnt & 1) st[i] = false;
                    cnt = 0;
                }
                else cnt++;
            }
            if(cnt & 1) st[i] = false;
        }
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1; i <= m; i++)
            for(int j = 0; j < 1 << n; j++)
                for(int k = 0; k < 1 << n; k++)
                    if((j & k) == 0 && st[j | k])
                        dp[i][j] += dp[i - 1][k];
        cout << dp[m][0] <<endl;
    }
    return 0;
}