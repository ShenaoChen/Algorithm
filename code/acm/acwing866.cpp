#include<iostream>

using namespace std;

bool isPrime(int n){
    if(n < 2)
        return false;
    for(int i = 2; i <= n/i; i ++ )
        if(n % i == 0)
            return false;
    return true;
}

int main(){
    int n, a;
    cin>>n;
    while(n--){
        cin>>a;
        if(isPrime(a)) puts("Yes");
        else puts("No");
    }
    return 0;
}