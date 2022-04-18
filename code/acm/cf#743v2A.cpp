#include<bits/stdc++.h>
using namespace std;
int main(){
    int ans,t,n;
    string s;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>s;
        for(int i=0;i<n-1;i++)
            if(s[i]!='0')
                ans+=s[i]-'0'+1;
        ans+=s[n-1]-'0';
        printf("%d\n",ans);
    }
    return 0;
}