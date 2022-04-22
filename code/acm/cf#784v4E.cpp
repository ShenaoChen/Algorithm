#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 15;

int cnt1[N][N], cnt2[N][N];

void solve() {
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cnt1[s[0] - 'a'][s[1] - 'a']++;
        cnt2[s[1] - 'a'][s[0] - 'a']++;
    }
    ll res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = j + 1; k < N; k++) {
                res += 1ll * cnt1[i][j] * cnt1[i][k];
                res += 1ll * cnt2[i][j] * cnt2[i][k];
            }
    cout << res << endl;
}

int main() {    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}