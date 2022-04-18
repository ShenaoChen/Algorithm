#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int a[N];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int i = 0, j = 1;
    while(i < n && j < n){
        if(a[j] - a[i] == k){
            cout << "YES" << endl;
            return;
        }
        if(a[j] - a[i] < k) j++;
        if(a[j] - a[i] > k) i++;
    }
    cout << "NO" <<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}