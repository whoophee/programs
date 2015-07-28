#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ll ans = 0,sum,i;
    sum = 0;
    for(i = 1;i <= 100;i++){
        ans += 2*sum*i;
        sum += i;
    }
    cout<<ans;
}
