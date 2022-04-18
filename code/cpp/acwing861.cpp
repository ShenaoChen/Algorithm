#include<cstring>
#include<iostream>

using namespace std;

const int N = 510, M = 10010;

int n1,n2,m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int a,b;
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n1, &n2, &m);
    while(m -- ){
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int res = 0;
    for(int i=1; i <= n1; i ++){
        memset(st, 0, sizeof st);
        if(find(i)) res ++ ;
    }

    cout<<res<<endl;

    return 0;
}