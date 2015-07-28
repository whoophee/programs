#include <iostream>
using namespace std;
#define ll long long
#define MOD 1000000000

ll ans[4001][4001];
ll comb[4001][4001];
ll req[4001];

int main() {
    ll i,j,prev,t,m,n,size,x,y;
    cin >> t;
    for(i = 0; i < 4001; i++)
        comb[i][0] = comb[0][i] = comb[i][i] = 1;
    for(i = 1; i < 4001; i++)
        for(j = 1; j < i; j++)
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
    while(t--) {
        cin >> n >> m;
        
        for(i = 0; i <= m; i ++)
            for( j = 0; j < n; j++)
                ans[i][j] = 0;

        req[0] = 1;
        ans[0][0] = 1;
        for(i = 1; i <= m; i++) {
            req[i] = comb[m+i-1][m-1];
            ans[0][i] = (req[i] + ans[0][i-1]) % MOD;
        }
        for(j = 0; j < n+1; j++)
            ans[j][0] = 1;
        for(i = 1; i < n; i++) {
            for(j = 1; j <= m; j++) {
                ans[i][j] = (req[j]*ans[i-1][j] + ans[i][j-1]) % MOD;
            }
        }
        cout << ans[n-1][m] << endl;
    }
    cin>>i;
}
