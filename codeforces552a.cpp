#include <cstdio>
#define ll long long
int readInt () {
	bool minus = false;
	int result = 0;
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
		return -result;
	else
		return result;
}
using namespace std;
int main(){
    int n,x1,y1,x2,y2,sum = 0;
    n = readInt();
    while(n--){
        x1 = readInt();
        y1 = readInt();
        x2 = readInt();
        y2 = readInt();
        sum = sum + (x2-x1+1)*(y2-y1+1);
    }
    printf("%d",sum);
    scanf("%d",&n);
}
