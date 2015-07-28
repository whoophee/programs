#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[21][21],i,j;
int main(){
    for(i = 1;i < 21;i++)
        a[0][i] = a[i][0] = 1;
    for(i = 1;i < 21;i++){
        for(j = 1;j < 21;j++)
            a[i][j] = a[i-1][j]+a[i][j-1];
    }
    cout<<a[20][20];

}
