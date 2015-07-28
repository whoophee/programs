#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[101][101],counter = 1;
int i,j,t,k,m,lt;
int main(){
    for(i = 2;i <= 100;i++){
        for(j = 2;j <= 100;j++){
            if(a[i][j] != 1)
                counter++;
            for(t = 2;t < j;t++){
                if(j%t == 0){
                    k = t;m = 1;lt = 0;
                    while(k--){
                        m *= i;
                        if(m > 100){
                            lt = 1;
                            break;
                        }
                    }
                    if(lt == 1)
                        break;
                    k = j/t;
                    if(a[m][k] == 1)
                        counter--;
                    a[m][k] = 1;
                }
            }
        }
    }
    cout<<counter;
}
