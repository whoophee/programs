#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int sum(ll a,ll b){
    a = a/b;
    return (b*a*(a+1))/2;
}
int main(){
    ll ans,a,b,c;
    cout<<sum(999,3)+sum(999,5)-sum(999,15);
}
