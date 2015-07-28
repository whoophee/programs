#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,steps,i,j,maximum;
map<ll,int> a;
stack<ll> l;
int main(){
    a[1] = 0;
    for(i = 2;i < 1000001;i++){
        steps = 0;
        k = i;
        while(1){
            steps++;
            if(k%2 == 0)
                k /= 2;
            else
                k = 3*k + 1;
            if(a.find(k) != a.end()){
                a[i] = a.find(k)->second + steps;
                if(a[i] > a[maximum])
                    maximum = i;
                break;
            }
        }
    }
    cout<<maximum;
}
