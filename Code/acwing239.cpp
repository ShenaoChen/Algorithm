#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 10010;

int n, m, cnt = 1;
int s[N], d[N];
unordered_map<int, int> h;

int find(int x) {
    if (s[x] != x) {
        int root = find(s[x]);
        d[x] += d[s[x]];
        s[x] = root;
    }
    return s[x];
}

int get(int x) {
    if (h.count(x) == 0) h[x] = cnt++;
    return h[x];
}

int main() {
    bool flag = true;
    cin >> n >> m;
    for (int i = 0; i < N; i++) s[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b, fa, fb;
        string str;
        cin >> a >> b >> str;
        a = get(a - 1), b = get(b);
        fa = find(a), fb = find(b);
        int t = 0;
        if (str == "odd") t = 1;
        if (fa == fb) {
            if (d[a] + d[b] & 1 ^ t) {
                cout << i - 1 << endl;
                flag = false;
                break;
            }
        }
        else {
            s[fa] = fb; 
            d[fa] = d[a] ^ d[b] ^ t;
                          
        } 
    }
    if (flag)
        cout << m << endl;
    return 0;
}