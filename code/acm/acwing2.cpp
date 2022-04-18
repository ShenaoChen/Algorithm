#include <iostream>

using namespace std;

const int N = 1010;

int v[N], w[N], dp[N];

int main(){
    int n, C;
    cin>>n>>C;
    for(int i = 1; i <= n; i++){
        cin>>v[i]>>w[i];
    }
    for(int i = 1; i <= n; i++)
        for(int j = C; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout<< dp[C] <<endl;
    return 0;
}