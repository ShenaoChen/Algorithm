#include<bits/stdc++.h>
using namespace std;
bool check(string s){
    int len=s.size();
    for(int i=1;i<len;i++){
        if(s[i]==s[0])
            return 0;
    }
    return 1;
}
int main(){
    int n;
    string s;
    cin>>n>>s;
    if(!check(s))
        cout<<"Wrong Answer"<<endl;
    else
        cout<<"Correct"<<endl;
    return 0;
}