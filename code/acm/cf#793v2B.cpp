#include <iostream>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        int ans = 0x3fffffff;
        for (int i = 0; i < n; i++)
            if (a[i] != i)
                ans &= i;
        cout << ans << endl;
    }
    return 0;
}