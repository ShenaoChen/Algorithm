#include<bits/stdc++.h>
using namespace std;
int n,t;
string s;
bool prime[100];
void solve(){
    for(int i=0;i<s.size();i++)
        if(s[i]=='1'||s[i]=='4'||s[i]=='6'||s[i]=='8'||s[i]=='9'){
            printf("1\n%d\n",s[i]-'0');
            return;
        }
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(prime[10*(s[i]-'0')+s[j]-'0']){
                printf("2\n%d%d\n",s[i]-'0',s[j]-'0');
                return;
            }
        }
    }
}
int main(){
    prime[1]=1;
    for(int i=2;i<100;i++){
        for(int j=i+i;j<100;j+=i)
            prime[j]=1;
    }
    cin>>t;
    while(t--){
        scanf("%d",&n);
        cin>>s;
        solve();
    }
    return 0;
}