#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    string s;
    vector<int> res, f;
    cin >> n >> k >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if ((s[i] - '0') ^ (k  & 1) == 0 && cnt < k)
            f.push_back(1), cnt++;
        else
            f.push_back(0);
    }
    f[n - 1] += k - cnt;
    for (int i = 0; i < n; i++)
        res.push_back((s[i] - '0') ^ ((k - f[i]) & 1));
    for (auto c : res)
        cout << c;
    cout << endl;
    for (auto c : f)
        cout << c << ' ';
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}