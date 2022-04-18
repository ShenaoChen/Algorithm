#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int sum[N];
bool isLeap(int x){
    return x%100!=0&&x%4==0||x%400==0;
}
int check(int x){
    if(x/10==202||x%1000==202)
        return 1;
    if(x%10==2)
        return 2;
    return 0;
}
int day(int a,int b,int c){
    if(b==1)
        return c;
    if(b==2)
        return c+31;
    int res=0;
    if(b<=7){
        res=b/2*31+(b-1)/2*30+c;
        res-=(isLeap(a)?1:2);
    }
    else{
        res=214+(b-8)/2*31+(b-7)/2*30+c;
        res-=(isLeap(a)?1:2);
    }
    return res;
}
void init(){
    for(int i=2000;i<=9999;i++){
        if(check(i)==1){
            if(isLeap(i))
                sum[i]=sum[i-1]+366;
            else
                sum[i]=sum[i-1]+365;
        }
        else if(check(i)==2){
            if(isLeap(i))
                sum[i]=sum[i-1]+30;
            else
                sum[i]=sum[i-1]+29;
        }
        else 
            sum[i]=sum[i-1]+2;
    }
}
int l(int a,int b,int c){
    if(check(a)==1){
        if(isLeap(a))
            return 366-day(a,b,c)+1;
        else
            return 365-day(a,b,c)+1;
    }
    else if(check(a)==2){
        if(b==1)
            return (isLeap(a)?30:29);
        else if(b==2)
            return (isLeap(a)?30-c+1:29-c+1);
        else if(b<12)
            return 1;
        else
            return (c<=2?1:0);
    }
    else{
        if(b==1)
            return 2;
        else if(b==2)
            return (c<=2?2:1);
        else if(b<12)
            return 1;
        else
            return (c<=2?1:0);
    }
}
int r(int a,int b,int c){
    if(check(a)==1)
        return day(a,b,c);
    else if(check(a)==2){
        if(b==1)
            return 0;
        else if(b==2)
            return c;
        else if(b<12)
            return (isLeap(a)?29:28);
        else{
            if(c>=2)
                return (isLeap(a)?30:29);
            else
                return (isLeap(a)?29:28);
        }
    }
    else{
        if(b==1)
            return 0;
        else if(b==2)
            return (c<2?0:1);
        else if(b<12)
            return 1;
        else
            return (c<2?1:2);
    }
}
void solve(){
    int a1,b1,c1,a2,b2,c2,ans=0;
    scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);
    if(a1==a2){
        ans=r(a2,b2,c2)-r(a1,b1,c1);
        if(c1==2&&(b1==2||b1==12)||check(a1)==1||check(a1)==2&&b1==2)
            ans++;
        printf("%d\n",ans);
        return;
    }
    ans+=sum[a2-1]-sum[a1];
    ans+=l(a1,b1,c1)+r(a2,b2,c2);
    printf("%d\n",ans);
}
int main(){
    int t;
    init();
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}