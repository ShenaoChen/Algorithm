#include<iostream>
#include<vector>

using namespace std;

const int N = 20010;

int s[N], cnt[N], dp[N];
vector<int> w;

int find(int x){
    if(s[x] != x){
        s[x] = find(s[x]);
    }
    return s[x];
}

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        s[i] = i;
        cnt[i] = 1;
    }
    for(int i = 0; i < k; i++){
        int a, b;
        cin>>a>>b;
        a = find(a);
        b = find(b);
        if(a != b){
            s[a] = b;
            cnt[b] += cnt[a];
        }
    }
    for(int i = 1; i <= n; i++){
        if(s[i] == i)
            w.push_back(cnt[i]);
    }
    for(int i = 0; i < w.size(); i++){
        for(int j = n; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
    } 
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(abs(dp[i] - m) < abs(ans - m))
            ans =  dp[i];
    }
    cout<< ans <<endl;
    return 0;
}