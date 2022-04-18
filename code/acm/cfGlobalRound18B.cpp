#include<iostream>

using namespace std;

const int N = 2e5+5;

int sum[N][32];

int main(){
    for(int i = 1; i < N; i++){
        int num = i;
        for(int j = 0; j < 32; j++){
            if(num == 0)
                break;
            sum[i][j] = sum[i-1][j] + (num & 1);
            num >>= 1;
        }
    }
    // for(int i = 1; i < 10; i++){
    //     for(int j = 0; j < 4; j++)
    //         cout<<sum[i][j]<<' ';
    //     cout<<endl;
    // }
    int t, l, r, ans;
    cin>>t;
    while(t--){
        ans = N;
        cin>>l>>r;
        int n = r - l + 1;
        for(int i = 0; i < 32; i++)
            ans = min(ans, n - (sum[r][i] - sum[l - 1][i]));
        cout<<ans<<endl;
    }
    return 0;
}