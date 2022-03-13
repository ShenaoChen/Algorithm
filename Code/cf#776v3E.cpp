#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;

int n, d;

int cnt(vector<int> &schedule){
    int mx = 0, mn = inf;
    for(int i = 1; i < n; i++){
        mx = max(mx, schedule[i] - schedule[i - 1] - 1);
        mn = min(mn, schedule[i] - schedule[i - 1] - 1);
    }
    return min(mn, max(d - schedule.back() - 1, (mx - 1) / 2));
}

void solve(){
    cin>>n>>d;
    vector<int> a(n + 1);
    vector<int> schedule;
    int mn = inf, pos = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] - a[i - 1] - 1 < mn){
            mn = a[i] - a[i - 1] - 1;
            pos = i;
        }
    }
    for(int i = 0; i <= n; i++)
        if(i != pos)
            schedule.push_back(a[i]);
    int ans = cnt(schedule);
    if(pos > 1){
        schedule[pos - 1] = a[pos];
        ans = max(ans, cnt(schedule));
    }
    cout<< ans <<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
