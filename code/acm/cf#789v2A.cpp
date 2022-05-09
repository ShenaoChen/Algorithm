#include <iostream>
#include <cstring>

using namespace std;

int a[105];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof a);
        int n;
        cin >> n;
        int tmp, cnt = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            if (tmp == 0) flag = true;
            else {
                a[tmp]++;
                if (a[tmp] > 1) flag = true;
                cnt++;
            }
        }
        if (!flag) cnt++;
        cout << cnt << endl;
    }
    return 0;
}