#include <iostream>
#include <vector>

using namespace std;

vector<string> c;
int dp[15][15];

void solve(){
    string str;
    int cnt, ans = 0;
    cin>>str>>cnt;
    int m = str.size();
    str = ' ' + str;
    for(auto a : c){
        int n = a.size();
        a = ' ' + a;
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int i = 0; i <= m; i++) dp[0][i] = i;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                if(a[i] == str[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
        if(dp[n][m] <= cnt) ans++;
    }
    cout << ans <<endl;
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        string tmp;
        cin>>tmp;
        c.push_back(tmp);
    }
    for(int i = 0; i < m; i++)
        solve();
    return 0;
}