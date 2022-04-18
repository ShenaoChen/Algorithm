#include<iostream>
#include<cstring>

using namespace std;

int cnt[30];

int main(){
    int t;
    cin>>t;
    while(t--){
        memset(cnt, 0, sizeof(cnt));
        string s;
        cin>>s;
        for(int i = 0; i < s.size(); i++)
            cnt[s[i] - 'a']++;
        for(int i = 0; i < 30; i++)
            if(cnt[i] == 2)
                cout<< (char)('a' + i) << (char)('a' + i);
        for(int i = 0; i < 30; i++)
            if(cnt[i] == 1)
                cout<< (char)('a' + i);
        cout<<endl;
    }
    return 0;
}