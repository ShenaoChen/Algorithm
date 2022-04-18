#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

vector<int> a[N], b[N];

int main(){
    int n, m, tmp;
    ll ans = 0;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>tmp;
            a[tmp].push_back(i);
            b[tmp].push_back(j);
        }
    }
    for(int i = 0; i < N; i++){
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
        for(int j = 0; j < a[i].size(); j++)
            ans += (2 * j - a[i].size() + 1) * a[i][j];
        for(int j = 0; j < b[i].size(); j++)
            ans += (2 * j - b[i].size() + 1) * b[i][j];
    }
    cout<< ans <<endl;
    return 0;
}