#include<iostream>
#include<vector>

using namespace std;

int main(){
    string str;
    vector<int> a;
    cin>>str;
    int n = str.size();
    for(int i = 0; i < n; i++){
        if(str[i] >= '0' && str[i] <= '9')
        a.push_back(str[i] - '0');
    }
    int tmp = 0;
    for(int i = 0; i < 9; i++)
        tmp += a[i] * (i + 1);
    tmp %= 11;
    if(tmp == str[n - 1] - '0' || tmp == 10 && str[n - 1] == 'X')
        cout<<"Right"<<endl;
    else{
        str[n - 1] = (tmp == 10 ? 'X' : tmp + '0');
        cout<<str<<endl;
    }
    return 0;
}