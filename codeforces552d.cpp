#include<cstdio>
#include<map>
#define BIGINT long long int
using namespace std;
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
int main(){
    int n,i;
    readInt(n);
    int x[n],y[n];float slope[i];
    map<float,bool> k ; 
    for(i = 0;i < n;i++){
        readInt(x[i]);readInt(y[i]);
    }
}
