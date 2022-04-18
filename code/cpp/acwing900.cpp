#include <iostream>

using namespace std;

const int N = 1010;
const int mod = 1e9 + 7;

int dp[N];

int main(){
    int n;
    cin>>n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++){
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    cout << dp[n] << endl; 
    return 0;
}