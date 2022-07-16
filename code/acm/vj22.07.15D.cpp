#include <iostream>

using namespace std;

int g[3][3];

int main() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> g[i][j];
    g[1][1] = (g[0][1] + g[2][1]) / 2;
    g[0][0] = g[1][0] + g[1][1] + g[1][2] - g[1][0] - g[2][0];
    g[2][2] = g[1][0] + g[1][1] + g[1][2] - g[2][0] - g[2][1];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << g[i][j] <<  ' ';  
        }
        cout << endl;
    }
    return 0;
}