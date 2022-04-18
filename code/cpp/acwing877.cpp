#include <iostream>

using namespace std;

int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int tmp = y;
    y = x - (a / b) * y;
    x = tmp;
    return d;
}

int main(){
    int n, a, b, x, y;
    cin >> n;
    while(n--){
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << ' ' << y << endl;
    }
    return 0;
}