#include <iostream>

using namespace std;

const int N = 110;

string str[N];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> str[i];
    cout << str[0];
    for (int i = 1, cnt = str[0].size(); i < n; i++){
        cnt += str[i].size();
        if (cnt <= k)
            cout << ' ' << str[i];
        else{
            cout << endl;
            cout << str[i];
            cnt = str[i].size();
        }
    }
    return 0;
}