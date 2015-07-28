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
const int MAXN = 1e6 + 5;
pairll a[MAXN];
priority_queue<pairll> q;
int ans[MAXN];
map<ll,vector<int> > b;

int main(){
    ll n,m,i,x;
    readInt(n);readInt(m);
    loop(i,0,n){
        readInt(a[i].fi);
        readInt(a[i].sc);
    }
    loop(i,0,n-1)
        q.push(make_pair(a[i+1].fi-a[i].sc,i));
    loop(i,0,m){
        readInt(x);
        b[x].push_back(i);
    }
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        ll min_gap = t.fi;
        ll max_gap = a[t.sc+1].sc-a[t.sc].fi;
        auto it = b.lower_bound(min_gap);
        if(it==b.end()){
            cout<<"No";
            return 0;
        }
        auto it2 = b.lower_bound(max_gap);
        if(it2 != b.begin() || (it2 != b.end() && it2->first == max_gap)){
            if(it2 -> fi != max_gap)
                --it2;
            ll gap = it2 -> fi;
            if(gap >= min_gap){
                ll idx = b[gap].back();
                b[gap].pop_back();
                if(b[gap].empty())
                    b.erase(gap);
                ans[t.sc] = idx;
            }else{
                cout<<"No";
                return 0;
            }
        }else{
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes\n";
    loop(i,0,n-1)    cout<<ans[i]+1<<" ";
}
