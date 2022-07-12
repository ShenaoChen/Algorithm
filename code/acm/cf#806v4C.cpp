#include <iostream>

using namespace std;

const int N = 105;

int last[N];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        string s;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> last[i];
        for (int i = 0; i < n; i++) {
            cin >> m >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] == 'D')
                    last[i] = (last[i] + 1) % 10;
                else
                    last[i] = (last[i] - 1 + 10) % 10;
            }
            cout << last[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}