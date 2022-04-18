#include<iostream>
#include<vector>

using namespace std;

const int inf = 0x3f3f3f3f;

bool st[1005];

int main(){
    vector<int> prime;
    for(int i = 2; i <= 1000; i++){
        for(int j = 2; j <= i / j; j++){
            if(i % j == 0){
                st[i] = true;
                break;
            }
        }
    }
    for(int i = 2; i <= 1000; i++){
        if(!st[i])
            prime.push_back(i);
    }
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int ans, tmp = inf;
        for(auto p : prime){
            if(abs(p - n) < tmp){
                tmp = abs(p - n);
                ans = p;
            }
        }
        cout<< ans <<endl;
    }
    return 0;
}