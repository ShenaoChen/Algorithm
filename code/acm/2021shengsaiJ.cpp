#include <iostream>
#include <map>

using namespace std;

map<int, int> m;
int a[3][4];

int main() {
    m[0] = 0;
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 4; j++) 
            cin >> a[i][j];
    if (a[1][3] == 0) {
        if(a[0][0]) {
            m[a[1][0]] = a[1][2];
            m[a[1][2]] = a[1][0];
            m[a[1][1]] = a[2][3];
            m[a[2][3]] = a[1][1];
            m[a[0][0]] = a[2][2];
            m[a[2][2]] = a[0][0];
        }
        else {
            m[a[1][0]] = a[1][2];
            m[a[1][2]] = a[1][0];
            m[a[1][1]] = a[2][3];
            m[a[2][3]] = a[1][1];
            m[a[0][2]] = a[2][2];
            m[a[2][2]] = a[0][2];
        }
    }
    else {
        m[a[1][0]] = a[1][2];
        m[a[1][2]] = a[1][0];
        m[a[1][1]] = a[1][3];
        m[a[1][3]] = a[1][1];
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < 4; i++) {
            sum1 += a[0][i];
            sum2 += a[2][i];
        }
        m[sum1] = sum2;
        m[sum2] = sum1;
    }
    bool flag = true;

    for(int i = 0; i < 3; i++) 
        for(int j = 0; j < 4; j++) 
            cin >>  a[i][j];
    if(a[1][3] == 0) {
        if(a[0][0]) {
            if(m[a[1][0]] != a[1][2]) flag = false;
            if(m[a[1][2]] != a[1][0]) flag = false;
            if(m[a[1][1]] != a[2][3]) flag = false;
            if(m[a[2][3]] != a[1][1]) flag = false;
            if(m[a[0][0]] != a[2][2]) flag = false;
            if(m[a[2][2]] != a[0][0]) flag = false;
        }
        else {
            if(m[a[1][0]] != a[1][2]) flag = false;
            if(m[a[1][2]] != a[1][0]) flag = false;
            if(m[a[1][1]] != a[2][3]) flag = false;
            if(m[a[2][3]] != a[1][1]) flag = false;
            if(m[a[0][2]] != a[2][2]) flag = false;
            if(m[a[2][2]] != a[0][2]) flag = false;
        }
    }
    else {
        if(m[a[1][0]] != a[1][2]) flag = false;
        if(m[a[1][2]] != a[1][0]) flag = false;
        if(m[a[1][1]] != a[1][3]) flag = false;
        if(m[a[1][3]] != a[1][1]) flag = false;
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < 4; i++) {
            sum1 += a[0][i];
            sum2 += a[2][i];
        }
        if(m[sum1] != sum2) flag = false;
        if(m[sum2] != sum1) flag = false;
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}