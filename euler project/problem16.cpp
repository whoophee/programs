#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500],len = 1;
int pow2(int i){
    if(i == 0)
        return 0;
    int k = 0,carry = 0;
    while(k < len){
        a[k] = (a[k]*2) + carry;
        carry = a[k]/10;
        a[k] = a[k]%10;
        k++;
    }
    if(carry == 1)
        a[len++] = 1;
    pow2(i-1);
}
int main(){
    a[0] = 1;ll s = 0;
    int i;
    pow2(1000);
    for(i = len-1;i >= 0;i--)
        s += a[i];
    cout<<s;
}
