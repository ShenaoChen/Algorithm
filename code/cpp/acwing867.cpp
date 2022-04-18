#include<iostream>
#include<vector>

using namespace std;

void divide(int x){
    for(int i = 2; i < x / i; i ++ ){
        if(x % i == 0){
            int cnt = 0;
            while(x % i == 0){
                cnt ++;
                x /= i;
            }
            cout<<i<<' '<<cnt<<endl;
        }
    }
    if(x > 1)
        cout<<x<<' '<<1<<endl;
    cout<<endl;
}

int main(){
    int n, x;
    cin>>n;
    while(n -- ){
        cin>>x;
        divide(x);
    }
    return 0;
}