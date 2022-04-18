#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='L')
                printf("L");
            if(s[i]=='R')
                printf("R");
            if(s[i]=='U')
                printf("D");
            if(s[i]=='D')
                printf("U");
        }
        printf("\n");
    }
    return 0;
}