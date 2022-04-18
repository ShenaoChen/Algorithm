#include<iostream>

using namespace std;

int main(){
    int t;
    string str;
    cin >> t;
    while(t--){
        cin>>str;
        int cnt = 0;
        for(int i = 0; i < str.size(); i++)
            if(str[i] == 'N')
                cnt++;
        if(cnt == 1)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}