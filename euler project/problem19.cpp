#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int d(int m,int y){
    int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(m != 2)
        return month[m-1];
    if(y%400 == 0)
        return 29;
    else if(y%100 == 0)
        return 28;
    else if(y%4 == 0)
        return 29;
    else
        return 28;
}
int main(){
    int i,j,t = 2,counter = 0;
    for(i = 1901;i < 2001;i++){
        for(j = 1;j <= 12;j++){
            t = (t+d(j,i))%7;
            if(t == 0)
                counter++;
        }
    }
    cout<<counter;

}
