#include<iostream>

using namespace std;

int a[500];

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    int ans = 0, x, y;
    cin>>x>>y;
    for(int i = x; i <= y; i++)
        ans += a[i];
    cout<< ans <<endl;
    return 0;
}