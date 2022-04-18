#include<iostream>

using namespace std;

const int inf = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    int minL = inf, costL = inf;
    int maxR = 0, costR = inf;
    int maxLen = 0, costLen = inf;

    for(int i = 0; i < n; i++){
        int l, r, c;
        cin>>l>>r>>c;
        if(l < minL)
            minL = l, costL = c;
        if(l == minL)
            costL = min(costL, c);
        
        if(r > maxR)
            maxR = r, costR = c;
        if(r == maxR)
            costR = min(costR, c);

        if(maxLen < r - l + 1)
            maxLen = r - l + 1, costLen = c;
        if(maxLen == r - l + 1)
            costLen = min(costLen, c);
        
        int ans = costL + costR;
        if(maxLen == maxR - minL + 1)
            ans = min(ans, costLen);
        cout<<ans<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}