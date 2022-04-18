#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int binarySearchLeft(int a[],int n,int x){
    int l=0,r=n-1,mid;
    while(l<r){
        mid=l+r>>1;
        if(a[mid]>=x)
            r=mid;
        else
            l=mid+1;
    }
    return a[r]==x?r:-1;
}
int binarySearchRight(int a[],int n,int x){
    int l=0,r=n-1,mid=l+r+1>>1;
    while(l<r){
        mid=l+r+1>>1;
        if(a[mid]<=x)
            l=mid;
        else 
            r=mid-1;
    }
    return a[l]==x?l:-1;
}
int main(){
    int n,q,k,l,r;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    while(q--){
        scanf("%d",&k);
        l=binarySearchLeft(a,n,k);
        r=binarySearchRight(a,n,k);
        printf("%d %d\n",l,r);
    }
    return 0;
}