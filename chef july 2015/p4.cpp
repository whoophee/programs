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
class neg{
    public:
    ll val;
    int index;
    int cost;
};
class judge{
    public:
    ll l,r,cost;
};
bool comp(judge a,judge b){
    if(a.cost < b.cost)
        return true;
    else
        return false;
}
neg a[100000];judge b[100000];ll l[100000],r[100000];
int searcher(ll v){
}
int main(){
    ll t,n,k,m,i,z,f,sum,j;
    readInt(t);
    while(t--){
        readInt(n);readInt(k);readInt(m);z = 0;sum = 0,minimum = MOD,maximum = 0;
        //the minimum cost to remove a negative value must be found efficiently
        loop(i,0,n){
            readInt(f);
            sum += f;
            if(f < 0){
                a[z].val = f;
                a[z].index = i;
            }
        }
        loop(i,0,m){
            readInt(b[i].l);readInt(b[i].r);readInt(b[i].cost);
        }
        sort(b,b+m,cmp);
        l[0] = b[0].l;r[0] = b[0].r;
        loop(i,1,m){
            if(b[i].l < l[i-1])
                l[i] = b[i].l;
            else
                l[i] = l[i-1];
            if(b[i].r > r[i-1])
                r[i] = b[i].r;
            else
                r[i] = r[i-1];
        }
        //if position of index in left array (l[]) is less than (r[])
        loop(i,0,z){
            a[i].cost = searcher(a[i].index);
        }
    }
}
