#include<iostream>
using namespace std;
const int N=1e5+5;
int e[N],ne[N],head,idx;
void init(){
    head=-1;
    idx=0;
}
void add(int x){
    e[idx]=x;
    ne[idx]=head;
    head=idx++;
}
void insert(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx++;
}
void del(int k){
    ne[k]=ne[ne[k]];
}
int main(){
    int n,k,x;
    char c;
    cin>>n;
    init();
    while(n--){
        cin>>c;
        if(c=='H'){
            scanf("%d",&x);
            add(x);
        }
        else if(c=='D'){
            scanf("%d",&k);
            if(k)
                del(k-1);
            else
                head=ne[head];
        }
        else{
            scanf("%d%d",&k,&x);
            insert(k-1,x);
        }
    }
    for(int i=head;i!=-1;i=ne[i])
        printf("%d ",e[i]);
    return 0;
}