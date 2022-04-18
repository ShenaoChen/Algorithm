#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int inf = 0x3f3f3f3f;

struct option{
    int t, p, id;
    option(int _t, int _p, int _id){
        t = _t, p = _p, id = _id;
    }
};

vector<int> get_ans(vector<option> &v, int &t){
    int n = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(101, inf));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        auto [t, p, id] = v[i - 1];
        dp[i][0] = 0;
        for(int j = 100; j > 0; j--){
            int prev = max(0, j - p);
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][prev] + t);
        }
    }
    vector<int> ans;
    t = dp[n][100];
    if(t == inf) return ans;
    for(int i = n, j = 100; i > 0; i--){
        if(dp[i][j] == dp[i - 1][j])
            continue;
        ans.push_back(v[i - 1].id);
        j = max(0, j - v[i - 1].p);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve(){
    int n, m, t;
    cin>>n>>m;
    vector<int> a(n);
    vector<vector<option>> v(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = n - 1; i > 0; i--)
        a[i] -= a[i - 1];
    for(int i = 1; i <= m; i++){
        int e, t, p;
        cin>>e>>t>>p;
        e--;
        v[e].emplace_back(t, p, i);
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        vector<int> cur = get_ans(v[i], t);
        if(t > a[i]){
            cout<<-1<<endl;
            return;
        }
        ans.insert(ans.end(), cur.begin(), cur.end());
        if(i < n - 1) a[i + 1] += a[i] - t;
    }
    cout<<ans.size()<<endl;
    for(auto p : ans)
        cout<< p <<' ';
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}