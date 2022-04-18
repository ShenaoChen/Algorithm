#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],cnt[2],p1,p2;
void swap(int &x,int &y){
    int t=x;
    x=y;
    y=t;
    
}
int main(){
    int t,n,ans1,ans2;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        cnt[0]=cnt[1]=0;
        ans1=ans2=0;
        p1=p2=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            a[i]%=2;
            b[i]=a[i];
            cnt[a[i]]++;
        }
        if(cnt[0]-cnt[1]>1||cnt[1]-cnt[0]>1){
            printf("-1\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=i%2){
                p1=p1>i?p1:i;
                p2=p2>i?p2:i;
                if(a[p1]%2==1){
                    while(a[p1]!=i%2&&p1<=n) p1++;
                    if(a[p1]==i%2){
                        swap(a[i],a[p1]);
                        ans1+=p1-i;
                    }
                    
                    
                }
                else{
                    while(a[p2]!=i%2&&p2<=n) p2++;
                    if(a[p2]==i%2){
                        swap(a[i],a[p2]);
                        ans1+=p2-i;
                    }
                    
                }
            }
        }
        p1=p2=1;
        for(int i=1;i<=n;i++){
            if(b[i]!=(i+1)%2){
                p1=p1>i?p1:i;
                p2=p2>i?p2:i;
                if(b[p1]%2==1){
                    while(b[p1]!=(i+1)%2&&p1<=n) p1++;
                    if(b[p1]==(i+1)%2){
                        swap(b[i],b[p1]);
                        ans2+=p1-i;
                    }
                    
                }
                else{
                    while(b[p2]!=(i+1)%2&&p2<=n) p2++;
                    if(b[p2]==(i+1)%2){
                        swap(b[i],b[p2]);
                        ans2+=p2-i;
                    }
                }
            }
        }
        if(cnt[0]==cnt[1])
            printf("%d\n",ans1<ans2?ans1:ans2);
        if(cnt[0]>cnt[1])
            printf("%d\n",ans2);
        if(cnt[1]>cnt[0])
            printf("%d\n",ans1);
    }
    return 0;
}