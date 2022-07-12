#include <iostream>

using namespace std;

const int N = 105;

string s[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        int cnt0, cnt1;
        int m = n / 2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cnt0 = 0, cnt1 = 0;
                for (int k = 0; k < 4; k++) {
                    if (s[i][j] == '0') cnt0++;
                    else cnt1++;
                    int tmp = j;
                    j = n - i - 1;
                    i = tmp;
                }
                ans += min(cnt0, cnt1);
            }
        }
        if (n & 1) {
            for (int i = 0, j = m; i < m; i++) {
                cnt0 = 0, cnt1 = 0;
                for (int k = 0; k < 4; k++) {
                    if (s[i][j] == '0') cnt0++;
                    else cnt1++;
                    int tmp = j;
                    j = n - i - 1;
                    i = tmp;
                }
                ans += min(cnt0, cnt1);
            }   
        }
        cout << ans << endl;
    }
    return 0;
}