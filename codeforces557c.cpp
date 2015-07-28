#include <bits/stdc++.h>
#define MOD (1000000007)
#define EPS (1e-9)
#define INF (2117117117)
#define LLINF (2117117117117117117LL)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define loop(i,j,n) for(i = j;i < n;i++)
#define fi first
#define sc second

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> pairll;
typedef pair<int,char> pairic;

//FAST INTEGER INPUT
template <class T>
int readInt ( T &x ) {
	bool minus = false;
	T result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		x = -result;
	else
		x = result;
	return 0;
}

//GENERATE nCr TRIANGLE
ll comb[4001][4001];
int ncr(){
    int i,j;
    for(i = 0; i < 4001; i++)
        comb[i][0] = comb[0][i] = comb[i][i] = 1;
    for(i = 1; i < 4001; i++)
        for(j = 1; j < i; j++)
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
    return 1;
}
class legs{
    public:
    ll l,d;
    legs(int a,int b){
        l = a;b = d;
    }
    legs(){
        l = 0;d = 0;
    }
};
bool cmp(legs a,legs b){
    if(a.l < b.l)
        return true;
    else
        return false;
}
ll cnt[201],tmpcnt[201],e[100005],tot,n,i,k,j,minimum,temp,m,r;
int main(){
    readInt(n);
    legs a[n];
    loop(i,0,n)readInt(a[i].l);
    loop(i,0,n)readInt(a[i].d);
    sort(a,a+n,cmp);
    tot = 0;
    for(i = n-2;i >= 0;i--){
        tot += a[i+1].d;
        e[i] = tot;
    }
    minimum = tot+a[0].d+1;
    loop(i,0,n){
        cnt[a[i].d]++;
        loop(j,0,201)
        tmpcnt[j] = cnt[j];
        temp = e[i];
        k = 0;
        for(j = i;j >= 0;j--)
            if(a[j].l == a[i].l){
                tmpcnt[a[j].d]--;
                k++;
            }
            else
                break;
        if(2*k <= (i+1)){
            m = 1+(i+1)-2*k;
            j = 0;
            while(m){
                if(tmpcnt[j] <= m){
                    m -= tmpcnt[j];
                    temp += j*tmpcnt[j];
                    j++;
                }
                else{
                    temp += m*j;
                    m = 0;
                }
            }
        }
        if(temp < minimum )
            minimum = temp;
    }
    cout<<minimum;
}
