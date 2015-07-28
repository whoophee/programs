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
class paired{
    public:
    ll a,minindex,maxindex,difference;
    paired(){
        a = 0;
        maxindex = -1;
        minindex = 1000001;
        difference = 0;
    }
}a[1000001];
ll n,k,i;
int main(){
    readInt(n);
    loop(i,0,n){
        readInt(k);
        a[k].a++;
        if(i > a[k].maxindex)a[k].maxindex = i;
        if(i < a[k].minindex)a[k].minindex = i;
        a[k].difference = a[k].maxindex - a[k].minindex;
    }
    k = 0;
    loop(i,0,1000001){
        if(a[i].a > a[k].a || (a[i].a==a[k].a && a[i].difference < a[k].difference))k = i;
    }
    cout<<a[k].minindex+1<<" "<<a[k].maxindex+1;
}
