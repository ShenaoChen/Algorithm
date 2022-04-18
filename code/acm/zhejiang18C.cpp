#include<bits/stdc++.h>
using namespace std;
bool check(int x,int y){
    if(x==0||y==0)
        return 0;
    if(x<y)
        swap(x,y);
    return x==y||x==2*y||x==3*y||2*x==3*y;
}
void solve(){
    int v[8][3]={0};
    vector<int>e;
    int len;
    for(int i=0;i<8;i++){
        for(int j=0;j<3;j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==j)
                continue;
            len=0;
            for(int k=0;k<3;k++)
                len+=(v[i][k]-v[j][k])*(v[i][k]-v[j][k]);
            e.push_back(len);
        }
    }
    for(int i=0;i<e.size()-1;i++){
        if(!check(e[i],e[i+1])){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}