#include <iostream>

using namespace std;

const int N = 105;

int s[N], v[N][N], w[N][N], dp[N];

int main(){
    int n, C;
    cin>>n>>C;
    for(int i = 1; i <= n; i++){
        cin>>s[i];
        for(int j = 1; j <= s[i]; j++)
            cin>>v[i][j]>>w[i][j];
    }
    for(int i = 1; i <= n; i++)
        for(int j = C; j >= 0; j--)
            for(int k = 1; k <= s[i]; k++)
                if(j >= v[i][k])
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
    cout<< dp[C] <<endl;
    return 0;
}