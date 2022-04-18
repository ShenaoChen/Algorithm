#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5;

double dp[N];
int a[N];
ll sum[N];

int main(){
    int t;
    int n, k;
    cin>>t;
    for(int Case = 1; Case <= t; Case++){
        cin>>n>>k;
        for(int i = 0; i < n; i++)
            scanf("%d", a + i);
        sort(a, a + n);
        sum[n] = 0;
        for(int i = n - 1; i >= 0; i--)
            sum[i] = sum[i + 1] + a[i];
        dp[0] = (double)sum[0] / n;
        for(int i = 1; i <= k; i++){
            int cnt = upper_bound(a, a + n, dp[i - 1]) - a;
            dp[i] = (cnt * dp[i - 1] + sum[cnt]) / n;
        }
        printf("Case #%d: %.7lf\n", Case, dp[k]);
    }
    return 0;
}