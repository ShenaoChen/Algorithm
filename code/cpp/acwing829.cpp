#include<iostream>
using namespace std;

const int N=1e5+5;
int a[N],hh,tt=-1;

int main(){
    string op;
    int x,n;
    cin>>n;
    while(n--){
        cin>>op;
        if(op=="push"){
            cin>>x;
            a[++tt]=x;
        }
        else if(op=="pop"){
            hh++;
        }
        else if(op=="empty")
            cout<<(tt<hh?"YES":"NO")<<endl;
        else
            cout<<a[hh]<<endl;
    }
    return 0;
}