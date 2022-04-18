#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp1(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

bool cmp2(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, c, w;
        int sum = 0;
        vector<vector<int>> v;
        cin>>n>>m;
        for(int i = 1; i <= m; i++){
            cin>>c>>w;
            v.push_back({i, c, w});
        }
        sort(v.begin(), v.end(), cmp1);
        v.erase(v.begin() + 2 * n, v.end());
        sort(v.begin(), v.end(), cmp2);
        for(auto p : v)
            sum += p[2];
        cout<<sum<<endl;
        for(int i = 0; i < n; i++){
            cout<<v[i][0]<<' '<<v[v.size() - i - 1][0]<<endl;
        }
        cout<<endl;
    }
    return 0;
}