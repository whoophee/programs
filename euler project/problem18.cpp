#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[15][15],i,j;
int main(){
    ifstream f("problem18.txt");
    f>>a[0][0];
    for(i = 1;i < 15;i++){
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
    int maximum = 0;
    for(i = 0;i < 15;i++)
        maximum = max(maximum,a[14][i]);
    cout<<maximum;
}
