#include <iostream>

using namespace std;

int main(){
    int t, n;
    string a, b;
    int sum1, sum2, cnt0, cnt1;
    cin>>t;
    while(t--){
        sum1 = 0;
        sum2 = 0;
        cnt0 = 0;
        cnt1 = 0;
        cin>>n>>a>>b;
        for(int i = 0; i < n; i++){
            if(a[i] == '0') cnt0++;
            if(a[i] == '1') cnt1++;
            if(a[i] == '0' && b[i] == '1')
                sum1++;
            if(a[i] == '1' && b[i] == '0')
                sum2++;
        }
        if(a == b)
            cout<<0<<endl;
        else if(sum1 != sum2 && cnt1 == 1 && sum1 == n - 1)
             cout<<1<<endl;
        else if(sum1 == sum2 && cnt0 == cnt1 - 1 && cnt0 < 2 * sum1)
            cout<<2 * (cnt0 - sum1) + 1<<endl;
        else if(sum1 == sum2)
            cout<<2 * sum1<<endl;
        else 
            cout<<-1<<endl;
    }
    return 0;
}