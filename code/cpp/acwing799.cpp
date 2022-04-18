#include<iostream>
using namespace std;
const int N=1e5+5;
int a[N],s[N];
int main(){
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0,j=0;i<n;i++){
        s[a[i]]++;
        while(s[a[i]]>1) s[a[j++]]--;
        ans=max(ans,i-j+1);
    }
    cout<<ans<<endl;
    return 0;
}