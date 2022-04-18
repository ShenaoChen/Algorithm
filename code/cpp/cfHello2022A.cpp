#include<iostream>

using namespace std;

int main(){
    int n, k, t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(2 * k - 1 > n){
            cout<<-1<<endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == i && j % 2 == 0 && i < 2 * k - 1)
                    cout<<'R';
                else
                    cout<<'.';
            }
            cout<<endl;
        }
    }
    return 0;
}