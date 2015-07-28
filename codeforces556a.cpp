#include<iostream>
#define BIGINT long long
using namespace std;
int main(){
    BIGINT n,i;
    cin>>n;
    char a[n];
    int stack[n],top = 0;
    cin>>a;
    stack[0] = (a[0]-'0');
    for(i = 1;i < n;i++){
        if(stack[top]+(a[i]-'0') == 1){
            top--;
        }
        else{
            stack[++top] = a[i]-'0';
        }
    }
    cout<<top+1;
}
