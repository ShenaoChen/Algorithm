#include <iostream>

using namespace std;

int a[1010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (a[i] <= a[j])
                    ans++;
        cout << ans << endl;
    }
    return 0;
}