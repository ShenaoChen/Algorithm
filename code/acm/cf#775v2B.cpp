#include<iostream>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        ll tmp, _max = 0, sum = 0;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>tmp;
            _max = max(_max, tmp);
            sum += tmp;
        }
        if (sum == 0)
            cout<<0<<endl;
        else if (_max <= sum / 2)
            cout<<1<<endl;
        else
            cout<< 2 * _max - sum <<endl;
    }
    return 0;
}