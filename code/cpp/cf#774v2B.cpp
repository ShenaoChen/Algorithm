#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

void solve(){
    int n, tmp;
    ll sum1 = 0, sum2 = 0;
    vector<int> v;
    cin>>n;
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    sum1 += v[0];
    for(int i = 1; i < n; i++){
        sum1 += v[i];
        sum2 += v[n - i];
        if(sum2 > sum1){
            cout<<"YES"<<endl;
            return;
        }
        if(i >= n / 2)
            break;
    }
    cout<<"NO"<<endl;
}

int main(){
    int t;    
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}