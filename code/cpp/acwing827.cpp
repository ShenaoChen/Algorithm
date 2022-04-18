#include<iostream>
using namespace std;
const int N=1e5+5;
int e[N],l[N],r[N],idx;
void insert(int a,int x){
    e[idx]=x;
    l[idx]=a,r[idx]=r[a];
    l[r[a]]=idx,r[a]=idx++;
}
void remove(int a){
    l[r[a]]=l[a];
    r[l[a]]=r[a];
}
int main(){
    r[0]=1,l[1]=0,idx=2;
    string op;
    int n,a,x;
    cin>>n;
    while(n--){
        cin>>op;
        if(op=="L"){
            cin>>x;
            insert(0,x);
        }
        else if(op=="R"){
            cin>>x;
            insert(l[1],x);
        }
        else if(op=="D"){
            cin>>x;
            remove(x+1);
        }
        else if(op=="IL"){
            cin>>a>>x;
            insert(l[a+1],x);
        }
        else{
            cin>>a>>x;
            insert(a+1,x);
        }
    }
    for(int i=r[0];i!=1;i=r[i])
        printf("%d ",e[i]);
    return 0;
}