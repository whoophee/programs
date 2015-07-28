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
class adj{
    public:
    int a,b,c;
    void ins(int l,int m,int n){
        a = l;b = m;c = n;
    }
    adj(){
        a = 0;b = 0;c = 0;
    }
};
const int frnt = 0, bck = 1, lft = 2, rght = 3, tp = 4, btm = 5;
int main(){
    adj a[8];ll t,n;int i,k;
    string c[6];
    a[0].ins(tp,frnt,lft);
    a[1].ins(tp,frnt,rght);
    a[2].ins(tp,bck,lft);
    a[3].ins(tp,bck,rght);
    a[4].ins(btm,frnt,lft);
    a[5].ins(btm,frnt,rght);
    a[6].ins(btm,bck,lft);
    a[7].ins(btm,bck,rght);
    cin>>t;
    while(t--){
        cin>>c[0]>>c[1]>>c[2]>>c[3]>>c[4]>>c[5];
        k = 0;
        for(i = 0;i < 8;i++){
            if(c[a[i].a] == c[a[i].b] && c[a[i].b] == c[a[i].c]){
                k = 1;
                break;
            }
        }
        if(k == 0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}
