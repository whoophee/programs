#include<iostream>
#include<cstdio>
#define ll long long
#define MOD 1000000007
using namespace std;

ll comb[4001][4001];
int main(){
    int i,j;
    for(i = 0; i < 4001; i++)
        comb[i][0] = comb[0][i] = comb[i][i] = 1;
    for(i = 1; i < 4001; i++)
        for(j = 1; j < i; j++)
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
    int n;
    cin>>n;
    ll ans = 1,k,spaces = 0,t;
    cin>>k;
    for(i = 1;i < n;i++){
        spaces += k;
        cin>>k;
        ans = (ans*comb[spaces+k-1][k-1]) % MOD;
    }
    cout<<ans;
}
