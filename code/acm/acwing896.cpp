#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e6 + 5;

int a[N], d[N];

int main(){
    int n, len = 1;
    cin>>n;
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    memset(d, 0x3f, sizeof d);
    d[1] = a[1];
    for(int i = 2; i <= n; i++){
        int r = lower_bound(d + 1, d + len + 1, a[i]) - d;
        d[r] = a[i];
        len = max(len, r);   
    }
    cout << len << endl;
}
