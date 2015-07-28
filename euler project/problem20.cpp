#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500],len;
int multiply(int m){
    int t = 0,carry = 0;
    while(t < len){
        a[t] = a[t]*m + carry;
        carry = a[t]/10;
        a[t] = a[t]%10;
        t++;
    }
    while(carry){
        a[len++] = carry%10;
        carry = carry/10;
    }
}
int main(){
    int t = 0,i;
    a[0] = 1;
    len = 1;
    for(i = 1;i <= 100;i++)
        multiply(i);
    for(i = 0;i < len;i++)
        t += a[i];
    cout<<t;
}
