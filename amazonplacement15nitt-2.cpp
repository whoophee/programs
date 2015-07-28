#include<bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long int i,p;
    int k = 0,j;
    cin>>p;
    bool a[64],shiftRequired = false;
    for(i = 0;i < 64;i++)
        a[i] = false;
    i = p;
    while(i){
        a[k++] = (i%2 == 0)?false:true;
        i /= 2;
    }
    for(i = k-1;i >= 1;i--){
        if(a[i]&a[i-1]){
            shiftRequired = true;
            break;
        }
    }
    if(shiftRequired){
        j = i;
        while(a[j]&a[j-1] && j < k){
            a[j+1] = true;
            a[j] = a[j-1] = false;
            j += 2;
        }
        if(j == k)
            k++;
        p = 0;
        for(j = k;j >= i;j--){
            if(a[j])
                p = p*2 + 1;
            else
                p = p*2;
        }
        cout<<(p<<i);
    }
    else
        cout<<p;
}
