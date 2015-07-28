#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow5[10],mindif[10];
ll tot = 0;
ll pow5sum(int k){
    ll sum = 0;
    while(k){
        sum += pow5[k%10];
        k = k/10;
    }
    return sum;
}
int main(){
    for(int i = 0;i < 10;i++){
        pow5[i] = i*i*i*i*i;
    }
    for(int i = 2;i < 10000000;i++){
        if(i == pow5sum(i))
            tot += i;
    }
    cout<<tot;
}
