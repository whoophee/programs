#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll lcm(ll a,ll  b){
    ll i = a,j = b,k;
    if(a < b)
        swap(i,j);
    while(1){
        k = i;
        i = j;
        j = k%i;
        if(j == 0)
            break;
    }
    return (a*b/i);
}
int main(){
    ll i = 20,j;ll ans = 1;
    while(i != 1){
        ans = lcm(i,ans);
        i--;
    }
    cout<<ans;
}
