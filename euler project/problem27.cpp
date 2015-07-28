#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll primearray[150000],z[2000000];
ll generate_primes(int n){
    primearray[0] = 2;
    ll k = 1;
    bool prime;
    ll i,j;
    for(i = 3;i <= n;i++){
        prime = true;
        for(j = 0;primearray[j] <= sqrt(i);j++)
            if(i%primearray[j] == 0){
                prime = false;
                break;
            }
        if(prime == true){
            z[i] = 1;
            primearray[k++] = i;
        }
    }
    return k;
}
int main(){
    generate_primes(2000000);//148933 primes
    int i,j,a,b,maximum = 0,ans;
    for(i = 0;primearray[i] < 1000;i++){
        b = primearray[i];
        for(a = 1-b;a < 1000;a++){
            j = 1;
            while(z[j*j + a*j +b] == 1)
                j++;
            if(j > maximum){
                maximum = j;
                ans = a*b;
            }
        }
    }
    cout<<ans;
}
