#include<iostream>
#include<cstring>

using namespace std;

const int null=0x3f3f3f3f;
const int N=200003;
int h[N];

int find(int x){
    int t=(x%N+N)%N;
    while(h[t]!=null&&h[t]!=x){
        t++;
        if(t==N) t=0;
    }
    return t;
}

int main(){
    int n,x;
    char op;
    cin>>n;
    memset(h,0x3f,sizeof(h));
    while(n--){
        scanf(" %c%d",&op,&x);
        if(op=='I')
            h[find(x)]=x;
        else
            printf(h[find(x)]==null?"No\n":"Yes\n");
    }
    return 0;
}