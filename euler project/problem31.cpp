#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[201];
int main(){
    ll total = 0,j,i;
    int b[] ={1,2,5,10,20,50,100,200};
    a[0] = 1;
    for(j = 0;j < 8;j++){
        for(i = 1;i < 201;i++){
            if(i >= b[j])
                a[i] += a[i-b[j]];
        }
    }
    cout<<a[200];
}
