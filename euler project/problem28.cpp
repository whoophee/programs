#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll i = 1,t,k;ll sum = 0;
    while(1){
        i = i*i;
        sum += i;
        if(sqrt(i) == 1001)
            break;
        k = sqrt(i)+1;
        sum += i+k + i+2*k+ i+3*k;
        i = sqrt(i)+2;
    }
    cout<<sum;
}
