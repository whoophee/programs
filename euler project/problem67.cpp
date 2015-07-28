#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100][100],i,j;
int main(){
    ifstream f("problem67.txt");
    f>>a[0][0];
    for(i = 1;i < 100;i++){
        for(j = 0;j <= i;j++){
            f>>a[i][j];
            if(j == 0)
                a[i][j] += a[i-1][j];
            else if(j == i)
                a[i][j] += a[i-1][j-1];
            else
                a[i][j] = max(a[i][j]+a[i-1][j],a[i][j]+a[i-1][j-1]);
        }
    }
    ll maximum = 0;
    for(i = 0;i < 100;i++)
        maximum = max(maximum,a[99][i]);
    cout<<maximum;
}
