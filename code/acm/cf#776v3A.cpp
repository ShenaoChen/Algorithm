#include<iostream>
#include<vector>

using namespace std;

void solve(){
    char c;
    string s;
    cin>>s;
    cin>>c;
    int n = s.size();
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(s[i] == c)
            v.push_back(i);
    }
    for(auto p : v){
        if(p % 2 == 0 && (n - p - 1) % 2 == 0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}