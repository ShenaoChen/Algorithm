#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

void solve(){
    int n, c, tmp;
    cin>>n>>c;
    vector<int> a;
    vector<int> b;
    vector<int> pre(c + 1);
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int pos = 1;
    if(a[0] != 1){
        cout<<"No"<<endl;
        return;
    }
    for(int i = 1; i < n; i++){
        pre[a[i]]++;
        while(pos < a[i]){
            pos++;
            if(pos != a[i])
                b.push_back(pos);
        }
    }
    for(int i = 1; i <= c; i++)
        pre[i] += pre[i - 1];
    for(auto u : b){
        for(auto v : a){
            ll l = 1ll * u * v;
            if(l > c) break;
            ll r = min(1ll * (u + 1) * v - 1, (ll)c);
            if(pre[r] - pre[l - 1] == 0) continue;
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}