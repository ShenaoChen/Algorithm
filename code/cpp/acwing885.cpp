#include <iostream>

using namespace std;

const int N = 2010, mod = 1e9 + 7;
int c[N][N];

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (j == 0) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << c[a][b] << endl;
    }
    return 0;
}