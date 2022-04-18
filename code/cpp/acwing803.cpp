#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
vector<PII> segs;
void merge(vector<PII>&segs){
    sort(segs.begin(),segs.end());
    vector<PII> res;
    int st=-2e9,ed=-2e9;
    for(auto seg:segs){
        if(seg.first>ed){
            if(st!=-2e9)
                res.push_back({st,ed});
            st=seg.first;
            ed=seg.second;
        }
        else
            ed=max(ed,seg.second);
    }
    if(st!=2e9)
        res.push_back({st,ed});
    segs=res;
}
int main(){
    int n,l,r;
    cin>>n;
    while(n--){
        scanf("%d%d",&l,&r);
        segs.push_back({l,r});
    }
    merge(segs);
    cout<<segs.size()<<endl;
    return 0;
}