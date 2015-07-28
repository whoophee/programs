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
#define MAX (1+(1<<20))

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


int tree[MAX];
int flip[MAX];
void build_tree(int node, int a, int b) {
  	if(a > b) return;
  	if(a == b) {
        tree[node] = 0;
        return;
	}
	build_tree(node*2, a, (a+b)/2);
	build_tree(node*2+1, 1+(a+b)/2, b);
	tree[node] = tree[node*2]+tree[node*2+1];
}
void update_tree(int node, int a, int b, int i, int j) {
  	if(flip[node] != 0) {
   		if(flip[node]%2)
            tree[node] = 1+(b-a)-tree[node];
		if(a != b) {
			flip[node*2] += flip[node];
    		flip[node*2+1] += flip[node];
		}
   		flip[node] = 0;
  	}
	if(a > b || a > j || b < i)
		return;
  	if(a >= i && b <= j) {
        tree[node] = 1+(b-a)-tree[node];
		if(a != b) {
			flip[node*2] += 1;
			flip[node*2+1] += 1;
		}
    	return;
	}
	update_tree(node*2, a, (a+b)/2, i, j);
	update_tree(1+node*2, 1+(a+b)/2, b, i, j);
	tree[node] = tree[node*2]+tree[node*2+1];
}
int query_tree(int node, int a, int b, int i, int j) {
	if(a > b || a > j || b < i) return 0;
	if(flip[node] != 0) {
        if(flip[node]%2)
            tree[node] = 1+(b-a)-tree[node];
		if(a != b) {
			flip[node*2] += flip[node];
			flip[node*2+1] += flip[node];
		}
		flip[node] = 0;
	}
	if(a >= i && b <= j)
		return tree[node];
	int q1 = query_tree(node*2, a, (a+b)/2, i, j);
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j);
	int res = q1+q2;
	return res;
}
int main(){
    ll n,q,t,l,r;
    readInt(n);readInt(q);
    build_tree(1,0,262143);
    while(q--){
        readInt(t);readInt(l);readInt(r);
        if(t == 0)
            update_tree(1,0,262143,l,r);
        else
            cout<<query_tree(1,0,262143,l,r)<<endl;
    }
}
