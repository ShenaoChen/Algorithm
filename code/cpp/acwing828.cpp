#include<iostream>
using namespace std;
const int N=1e5+5;
int a[N],top=-1;
void push(int x){
    a[++top]=x;
}
void pop(){
    top--;
}
int query(){
    return a[top];
}
bool empty(){
    return top==-1;
}
int main(){
    int n,x;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        if(s=="push"){
            cin>>x;
            push(x);
        }
        if(s=="pop"){
            pop();
        }
        if(s=="query"){
            cout<<query()<<endl;
        }
        if(s=="empty"){
            if(empty())
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}