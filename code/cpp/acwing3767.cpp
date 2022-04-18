#include <iostream>

using namespace std;

const int N = 105;

int a[N], b[N];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    bool flag = false;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > b[i])
            flag = true, cnt1++;
        if(b[i] > a[i])
            cnt2++;
    }
    if(!flag)
        cout << -1 << endl;
    else{
        cout << (cnt1 + cnt2) / 2 << endl;
    }
    return 0;
}