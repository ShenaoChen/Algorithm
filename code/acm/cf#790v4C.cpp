#include <iostream>

using namespace std;

string s[60];

int dif(string a, string b) {
    int n = a.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) res += a[i] - b[i];
        if (b[i] > a[i]) res += b[i] - a[i];
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        int mn = 1e8;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                mn = min(mn, dif(s[i], s[j]));
        cout << mn << endl;
    }
    return 0;
}