#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

int cnt[N];

void solve() {  
    int n;
    bool flag = false;
    cin >> n;
    memset(cnt, 0, sizeof(int) * (n + 1));
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        cnt[tmp]++;
        if (cnt[tmp] >= 3 && !flag) {
            cout << tmp << endl;
            flag = true;
        }
    }
    if (!flag)
        cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}