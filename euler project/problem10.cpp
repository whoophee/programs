#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll i,j,z,primearray[1000000],sum = 2;
int main(){
    bool m;
    primearray[0] = 2;
    j = 1;
    for(i = 3;i < 2000000;i++){
        m = true;
        for(z = 0;primearray[z] <= sqrt(i);z++){
            if(i%primearray[z] == 0){
                m = false;
                break;
            }
        }
        if(m){
            primearray[j++] = i;
            sum += i;
        }
    }
    cout<<sum;
}
