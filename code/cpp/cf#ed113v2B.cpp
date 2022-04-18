#include<bits/stdc++.h>
using namespace std;
char ans[55][55];
int main(){
    int n,len;
    string s;
    vector<int>C;
    cin>>n;
    while(n--){
        C.clear();
        memset(ans,'0',sizeof(ans));
        cin>>len>>s;
        for(int i=0;i<len;i++)
            ans[i][i]='X';
        for(int i=0;i<len;i++){
            if(s[i]=='2')
                C.push_back(i);
        }
        if(C.size()==1||C.size()==2){
            printf("NO\n");
            continue;
        }
        if(C.size()==0){
            printf("YES\n");
            for(int i=0;i<len;i++){
                for(int j=0;j<len;j++){
                    if(i!=j)
                        cout<<'=';
                    else
                        cout<<'X';
                }
                printf("\n");
            }
            continue;
        }
        for(int i=0;i<C.size()-1;i++){
            ans[C[i]][C[i+1]]='+';
            ans[C[i+1]][C[i]]='-';
        }
        ans[C[0]][C[C.size()-1]]='-';
        ans[C[C.size()-1]][C[0]]='+';
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                if(ans[i][j]=='0')
                    ans[i][j]='=';
        printf("YES\n");
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++)
                printf("%c",ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}