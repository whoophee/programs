#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int b[1000];
int recurlen(int a){
    int i,rcount = 0;
    for(i = 0;i < 1000;i++)b[i] = 0;
    i = 1;
    while(1){
        if(i < a){
            i *= 10;
            rcount++;
        }
        else{
            i = i%a;
            if(i == 0)
                return 0;
            else if(b[i] == 1)
                return rcount;
            else
                b[i] = 1;
        }
    }
}
int main(){
    int maximum = 0,t,i,r = 0;
    for(i = 1;i < 1000;i++){
        r = recurlen(i);
        if(r > maximum){
            maximum = r;
            t = i;
        }
    }
    cout<<t;
}
