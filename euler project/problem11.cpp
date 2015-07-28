#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int i ,j,a[20][20],row,col,diag1,diag2,maximum = 0;
    string s;
    ifstream f("problem11.txt");
    for(i = 0;i < 20;i++){
        for(j = 0;j < 20;j++){
            f>>s;
            a[i][j] = 10*(s[0]-'0')+(s[1]-'0');
            diag1 = diag2 = col = row = 0;
            if(i >= 3 && j >= 3)
                diag1 = a[i][j]*a[i-1][j-1]*a[i-2][j-2]*a[i-3][j-3];
            if(i >= 3 && j <= 16)
                diag2 = a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3];
            if(i >= 3)
                col = a[i][j]*a[i-1][j]*a[i-2][j]*a[i-3][j];
            if(j >= 3)
                row = a[i][j]*a[i][j-1]*a[i][j-2]*a[i][j-3];
                maximum = max(max(max(max(maximum,col),row),diag1),diag2);
        }
    }
    cout<<maximum;
}
