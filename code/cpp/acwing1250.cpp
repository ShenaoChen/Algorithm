#include <iostream>

using namespace std;

const int N = 40010;

int n, m;
int s[N];

int find(int x) {
    if (s[x] != x) s[x] = find(s[x]);
    return s[x];
}

int get(int x, int y) {
    return n * (x - 1) + y; 
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n * n; i++)
        s[i] = i;
    bool flag = false;
    for (int i = 1; i <= m; i++) {
        int x, y, a, b;
        char c;
        cin >> x >> y >> c;
        a = get(x, y);
        if (c == 'D') b = get(x + 1, y);
        else b = get(x, y + 1);
        a = find(a), b = find(b);
        if (a == b) {
            cout << i << endl;
            flag = true;
            break;
        }
        else
            s[a] =b;
    }
    if (!flag)
        cout << "draw" << endl;
    return 0;
}