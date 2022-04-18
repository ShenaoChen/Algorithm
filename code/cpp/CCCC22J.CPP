#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

ll sum[N];

bool check(int n, int m, int k){
    ll tmp;
    for(int i = 1, j = i + k - 1; j <= n; i++, j++){
        tmp = sum[j] - sum[i - 1];
        if(tmp >= m) return true;
    }
    return false;
}

int main(){
    int n, m, tmp;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        scanf("%d", &tmp);
        sum[i] = sum[i - 1] + tmp;
    }
    int l = 1, r = n, mid;
    while(l < r){
        mid = l + r >> 1;
        if(check(n, m, mid))
            r = mid;
        else
            l = mid + 1;
    }
    if(check(n, m, l))
        cout<<l<<endl;
    else
        cout<<0<<endl;
    return 0;
}