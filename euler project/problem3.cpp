#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

    ll i,j,z,primearray[100000];
int main(){
    ll k = 600851475143;
    bool m;
    primearray[0] = 2;
    j = 1;
    for(i = 3;i <= sqrt(k);i++){
        m = true;
        for(z = 0;primearray[z] <= sqrt(i);z++){
            if(i%primearray[z] == 0){
                m = false;
                break;
            }
        }
        if(m)
            primearray[j++] = i;
    }
    for(i = j-1;i >= 0;i--){
        if(k%primearray[i] == 0)
            break;
    }
    cout<<primearray[i];
}
