#include<iostream>
using namespace std;
const double eps=1e-6;
int main(){
    double x;
    cin>>x;
    double l=-10000,r=10000,mid=0;
    while(r-l>=eps){
        mid=(l+r)/2;
        if(mid*mid*mid>x)
            r=mid;
        else
            l=mid;
    }
    printf("%.6lf\n",r);
    return 0;
}