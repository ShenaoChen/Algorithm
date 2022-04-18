#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int n,len,flag;
    cin>>n;
    while(n--){
        cin>>len>>s;
        flag=0;
        for(int i=0;i<len-1;i++){
            if(s[i]!=s[i+1]){
                printf("%d %d\n",i+1,i+2);
                flag=1;
                break;
            }
        }
        if(!flag)
            printf("-1 -1\n");
    }
    return 0;
}