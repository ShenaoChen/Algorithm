#include<iostream>
#include<vector>

using namespace std;

bool check(vector<int> &s){
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

vector<int> fun(int a, int k){
    vector<int> res;
    while(a){
        res.push_back(a % k);
        a /= k;
    }
    return res;
}

int main(){
    int n;
    vector<int> ans;
    cin>>n;
    for(int i = 2; i <= 36; i++){
        vector<int> tmp = fun(n, i);
        if(check(tmp))
            ans.push_back(i);
    }
    cout<< ans.size() <<endl;
    for(auto p : ans)
        cout<< p <<endl;
    return 0;
}