#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> get_divisors(int x){
    vector<int> res;
    for(int i = 1; i <= x/i; i ++ ){
        if(x % i == 0){
            res.push_back(i);
            if(i != x/i)
                res.push_back(x/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    int n, x;
    cin>>n;
    while(n -- ){
        cin>>x;
        auto c = get_divisors(x);
        for(auto item : c)
            printf("%d ", item);
        printf("\n");
    }
    return 0;
}