#include<iostream>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<m;i++)
        scanf("%d",b+i);
    int i=0,j=-1;
    while(i<n&&j<m){
        j++;
        if(a[i]==b[j])
            i++;
    }
    printf(j==m?"NO\n":"YES\n");
    return 0;
}