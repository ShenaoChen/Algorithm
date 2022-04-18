#include<iostream>

using namespace std;

int main(){
    int t, n, tmp, sum;
    cin>>t;
    while(t--){
        cin>>n;
        sum = 0;
        for(int i = 0; i < n; i++){
            cin>>tmp;
            sum += tmp;
        }
        if(sum % n == 0)
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }

    return 0;
}
