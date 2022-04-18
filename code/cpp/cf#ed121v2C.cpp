#include<iostream>

using namespace std;

const int N = 10010;
typedef long long ll;

int h[N], k[N];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        ll ans = 0;
        int tmp = 1;
        cin>>n;
        h[0] = 0, k[0] = 0;
        for(int i = 1; i <= n; i++)
            cin>>k[i];
        for(int i = 1; i <= n; i++)
            cin>>h[i];
        for(int i = 1; i <= n; i++){
            if((k[i] - k[i - 1]) * (k[i] - k[i - 1] + 1) / 2 < h[i])
                tmp = (k[i] - k[i - 1]) * tmp + (k[i] - k[i - 1]) * (k[i] - k[i - 1] - 1) / 2;
            else
                tmp = h[i] * (h[i] + 1) / 2;
            ans += tmp;
        }
        cout<< ans <<endl;
    }
    return 0;
}