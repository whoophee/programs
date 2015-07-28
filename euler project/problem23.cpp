#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[30000],b[30000];
int main(){
    int i,j,k = 0,ending;ll s;
    for(i = 1;i < 30000;i++){
        s = 1;
        for(j = 2;j < sqrt(i);j++){
            if(i%j == 0)
                s += j + i/j;
        }
        if(j*j == i)
            s += j;
        if(s > i){
            b[k++] = i;
        }
    }
    ending = k;
    for(i = 0;i < ending;i++){
        for(j = i;j < ending;j++)
            if(b[i]+b[j] < 30000)
                a[b[i]+b[j]] = 1;
    }
    k = 0;
    for(i = 1;i <= 28123;i++)
        if(a[i] == 0)
        k += i;
    cout<<k;
}
