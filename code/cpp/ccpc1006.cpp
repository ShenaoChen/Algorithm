#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll M=998244353;
ll p[N];
ll dp[N][9];
ll sum[N];
ll ans[N];
void getP(){
    p[0]=1;
    for(int i=1;i<N;i++)
        p[i]=p[i-1]*2%M;
}
void getSum(string &s){
    int len=s.size();
    int cnt=0;
    for(int i=len-1;i>=0;i--){
        if(s[i]=='a')
            cnt++;
        sum[i]=(p[cnt]-1+M)%M;
    }
}
void run(string &s){
    int len=s.size();
    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<len;i++){
        if(i>0){
            for(int j=0;j<9;j++)
                dp[i][j]=dp[i-1][j]%M;
        }
        if(s[i]=='n'){
            dp[i][0]++;
            if(i>0)
                dp[i][2]=(dp[i-1][2]+dp[i-1][1])%M;
        }
        if(s[i]=='u'&&i>0){
            dp[i][1]=(dp[i-1][1]+dp[i-1][0])%M;
        }
        if(s[i]=='h'&&i>0){
            dp[i][3]=(dp[i-1][3]+dp[i-1][2])%M;
            dp[i][5]=(dp[i-1][5]+dp[i-1][4])%M;
            dp[i][6]=(dp[i-1][6]+dp[i-1][5])%M;
            dp[i][8]=(dp[i-1][8]+dp[i-1][7])%M;
        }
        if(s[i]=='e'&&i>0){
            dp[i][4]=(dp[i-1][4]+dp[i-1][3])%M;
            dp[i][7]=(dp[i-1][7]+dp[i-1][6])%M;
        }
        if(i>0)
            ans[i]=(ans[i-1]+((dp[i][8]-dp[i-1][8]+M)%M)*sum[i]%M)%M;
    }
    printf("%lld\n",ans[len-1]);
}
int main(){
    int t;
    getP();
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        getSum(s);
        run(s);
    }
    return 0;
}