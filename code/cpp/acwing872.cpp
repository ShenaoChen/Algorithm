#include<iostream>

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int n, a, b;
    cin>>n;
    while(n -- ){
        cin>>a>>b;
        cout<<gcd(a,b)<<endl;
    }
    return 0;
}