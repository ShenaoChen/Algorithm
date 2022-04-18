#include<iostream>
using namespace std;

const int N=1e5+5;
int stk[N],tt=-1;

int main(){
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        while(tt!=-1&&x<=stk[tt]) tt--;
        printf("%d ",tt==-1?-1:stk[tt]);
        stk[++tt]=x;
    }
    return 0;
}