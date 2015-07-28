#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int a = 1,b = 499,c;
    while(1){
        c = 1000-(b+a);
        if(a*a + b*b < c*c)
            a++;
        else if(a*a + b*b > c*c)
            b--;
        else break;
    }
    cout<<a*b*c;
}
