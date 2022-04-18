#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        string ans;
        cin>>s;
        int n = s.size();
        int pos = 1;
        for(int i = n - 1; i > 0; i--){
            if(s[i] - '0' + s[i - 1] - '0' >= 10){
                pos = i;
                break;
            }
        }
        for(int i = 0; i < pos - 1; i++)
            ans = ans + s[i];
        int tmp = s[pos] - '0' + s[pos - 1] - '0';
        if(tmp >= 10)
            ans += tmp / 10 + '0';
        ans += tmp % 10 + '0';
        for(int i = pos + 1; i < n; i++){
            ans += s[i];
        }
        cout<< ans <<endl;
    }
    return 0;
}