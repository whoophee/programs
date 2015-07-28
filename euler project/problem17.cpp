#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[] = {0,3,3,5,4,4,3,5,5,4};
int a1[] = {3,6,6,8,8,7,7,9,8,8};
int b[] = {0,3,6,6,5,5,5,7,6,6};
int length(int k){
    if(k == 1000)
        return 11;
    int r = 0,hundred = k/100,ten = (k%100)/10,one = k%10;
    r += a[hundred];
    if(hundred > 0){
        r += 7;
        if(ten + one > 0)
            r += 3;
    }
    if(ten == 1){
        r += a1[one];
    }
    else{
        r += b[ten] + a[one];
    }
    return r;
}
int main(){
    int sum = 0,i;
    for(i = 1;i <= 1000;i++)
        sum += length(i);
    cout<<sum;
}
