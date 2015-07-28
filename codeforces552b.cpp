#include<cstdio>
#define BIGINT long long
BIGINT readInt () {
	bool minus = false;
	BIGINT result = 0;
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
int main(){
    BIGINT n,k = 0,i = 0,arr[] = {9,90,900,9000,90000,900000,9000000,90000000,900000000};
    n = readInt();
    while(n > arr[i]){
        k += (i+1) * arr[i];
        n -= arr[i];
        i++;
    }
    k += (i+1) * n;
    printf("%I64d",k);
}
