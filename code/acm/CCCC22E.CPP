#include<iostream>

using namespace std;

void solve(int n, int k){
    if(n <= k)
        cout<< 2 <<endl;
    else{
        n *= 2;
        cout<< (n % k == 0 ? n / k : n / k + 1)<<endl;
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    solve(n, k);
    return 0;
}