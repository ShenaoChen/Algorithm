#include<iostream>
using namespace std;
const int N=1e5+5;
int son[N][26],cnt[N],idx;
void insert(string &s){
    int p=0;
    for(int i=0;s[i];i++){
        int u=s[i]-'a';
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];      
    }
    cnt[p]++;
}
int query(string &s){
    int p=0;
    for(int i=0;s[i];i++){
        int u=s[i]-'a';
        if(!son[p][u]) return 0;
        p=son[p][u];
    }
    return cnt[p];
}
int main(){
    int n;
    char c;
    cin>>n;
    string s;
    while(n--){
        cin>>c>>s;
        if(c=='I') insert(s);
        else printf("%d\n",query(s));
    }
    return 0;
}