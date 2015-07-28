#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int rev(int k){
    int j = 0;
    while(k){
        j = j*10+(k%10);
        k = k/10;
    }
    return j;
}
int main(){
    int k,j,i = 999;
    bool t = false;
    while(i--){
        k = i*1000+rev(i);
        j = sqrt(k);
        while(j > 100){
            if(k%j == 0 && k/j < 1000){
                t = true;
                break;
            }
            j--;
        }
        if(t)
            break;
    }
    cout<<k;
}
