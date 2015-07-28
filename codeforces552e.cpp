#include<cstdio>
#include<string>
#include<iostream>
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
    string expr;int i,length;
    cin>>expr;
    length = strlen(expr);
    int a[(length+1)/2][(length+1)/2];
    for(i = 1 ; i <= length ; i++){
        for(j = 0 ; j < length-i+1 ; i++){
            
        }
    }
}
