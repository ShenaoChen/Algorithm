#include<iostream>
#include<string.h>
using namespace std;
const int N=1e5+5;
int h[N],hp[N],ph[N],cnt;
void hash_swap(int a,int b){
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}
void up(int u){
    while(u/2&&h[u]<h[u/2]){
        hash_swap(u,u/2);
        u>>=1;
    }
}
void down(int u){
    int t=u;
    if(u*2<=cnt&&h[u*2]<h[t]) t=u*2;
    if(u*2+1<=cnt&&h[u*2+1]<h[t]) t=u*2+1;
    if(t!=u){
        hash_swap(t,u);
        down(t);
    }
}

int main(){
    int n,m=0;
    int k,x;
    char op[5];
    cin>>n;
    while(n--){
        scanf("%s",op);
        if(!strcmp(op,"I")){
            scanf("%d",&x);
            cnt++,m++;
            h[cnt]=x;
            ph[m]=cnt;
            hp[cnt]=m;
            up(cnt);
        }
        else if(!strcmp(op,"PM")) printf("%d\n",h[1]);
        else if(!strcmp(op,"DM")){
            hash_swap(1,cnt);
            cnt--;
            down(1);
        }
        else if(!strcmp(op,"D")){
            scanf("%d",&k);
            k=ph[k];
            hash_swap(k,cnt);
            cnt--;
            up(k);
            down(k);
        }
        else{
            scanf("%d%d",&k,&x);
            k=ph[k];
            h[k]=x;
            up(k);
            down(k);
        }
    }
    return 0;
}