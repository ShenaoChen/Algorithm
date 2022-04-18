#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[10],b[10],p[10],ta,tb;
    p[0]=1;
    for(int i=1;i<=10;i++)
        p[i]=p[i-1]*10;
    string s;
    cin>>n;
    while(n--){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        ta=0;
        tb=0;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(i%2==0)
                a[i/2]+=s[i]-'0';
            else
                b[i/2]+=s[i]-'0';
        }
        for(int i=0;i<s.size();i++){
            ta+=a[i]*p[(s.size()+1)/2-i-1];
            tb+=b[i]*p[s.size()/2-i-1];
        }
        printf("%d\n",(ta+1)*(tb+1)-2);
    }
    return 0;
}