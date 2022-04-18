#include<bits/stdc++.h>
using namespace std;
string s;
int n,k;
bool check(int n){
    int len=s.size(),pos=0,cnt=0;
    while(pos<len){
        if(s[pos]=='1'){
            cnt++;
            pos+=n;
        }
        else
            pos++;
    }
    return cnt<=k;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>s;
        int l=1,r=n,mid=0;
        while(l<r){
            mid=(l+r)>>1;
            if(check(mid))
                r=mid;
            else
                l=mid+1;
        }
        printf("%d\n",r);
    }
    return 0;
}