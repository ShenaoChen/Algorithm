#include<iostream>
using namespace std;
const int N=1e5+5;
int ne[N];
void getNe(string &p){
    ne[0]=-1;
    int i=0,j=-1;
    while(i<p.size()){
        if(j==-1||p[j]==p[i]){
            i++,j++;
            ne[i]=j;
        }
        else j=ne[j];
    }
}
int main(){
    string s,p;
    int m,n;
    cin>>m>>p>>n>>s;
    getNe(p);
    int i=0,j=0;
    while(i<n){
        if(j==-1||s[i]==p[j]) i++,j++;
        else j=ne[j];
        if(j==m){
            cout<<i-j<<' ';
            j=ne[j];
        }
    }
    return 0;
}