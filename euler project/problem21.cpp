#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10001];
int main(){
    int i,j;ll sum = 0;
    a[0] = 0;
    for(i = 1;i < 10001;i++){
        a[i] = 1;
        for(j = 2;j < sqrt(i);j++){
            if(i%j == 0)
                a[i] += j + i/j;
        }
        if(j*j == i)
            a[i] += j;
        if(a[i]>10000)
            a[i] = 0;
        cout<<a[i]<<endl;
    }
    for(i = 1;i < 10001;i++){
        if(a[i] != 0 && (a[a[i]] == i && a[i] != i))
            sum += i;
    }
    cout<<sum;
}
