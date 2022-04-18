#include<bits/stdc++.h>
using namespace std;
int a[1005];
void swap(int x,int y){
    int t=a[x];
    a[x]=a[y];
    a[y]=t;
}
int main(){
    int t,n,flag,cnt;
    cin>>t;
    while(t--){
        cin>>n;
        flag=1;
        cnt=0;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        while(true){
            flag=1;
            for(int i=1;i<n;i++){
                if(a[i]>a[i+1]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                cout<<cnt<<endl;
                break;
            }
            cnt++;
            if(cnt%2==1){
                for(int i=1;i<=n-2;i+=2)
                    if(a[i]>a[i+1])
                        swap(i,i+1);
            }
            else{
                for(int i=2;i<=n-1;i+=2)
                    if(a[i]>a[i+1])
                        swap(i,i+1);
            }
        }
    }
    return 0;
}