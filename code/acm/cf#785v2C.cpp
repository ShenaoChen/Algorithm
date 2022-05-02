#include <iostream>
#include <vector>

using namespace std;

const int N = 40010;
const int mod = 1e9 + 7;

int cnt = 1;
int a[N], dp[N];

bool check(int x) {
    vector<int> c;
    while (x) {
        c.push_back(x % 10);
        x /= 10;
    }
    int n = c.size();
    for (int i = 0; i < n; i++) {
        if (c[i] != c[n - i -1])
            return false;
    }
    return true;
}

int main() {
    for (int i = 1; i < N; i++) {
        if (check(i))
            a[cnt++] = i;
    }
    dp[0] = 1;
    for(int i = 1; i < cnt; i++)
        for(int j = a[i]; j < N; j++){
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}