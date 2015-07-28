#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int i,a,b;ll sum = 0;
    a = 1;b = 2;
    while(a < 4000000){
        b = a+b;
        a = b-a;
        if(a%2 == 0)
            sum =sum + a;
    }
    cout<<sum;
}
