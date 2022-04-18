#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[7];
    for(int i = 0; i < 7; i++)
        cin >> a[i];
    sort(a, a + 7);
    cout << a[0] <<' '<< a[1] << ' ';
    if(a[2] == a[0] + a[1])
        cout << a[3] << endl;
    else 
        cout << a[2] << endl;
    return 0;
}