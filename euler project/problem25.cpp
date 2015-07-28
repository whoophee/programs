//Naive implementation.
//Loop i*log(Phi)-0.5*log(5) for directly computing number of digits in a fibonacci number.
//http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibFormula.html
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr1[2000],arr2[2000],temp[2000],len = 1;
int add(){
    int carry = 0;
    for(int i = 0;i < len;i++){
        temp[i] = (arr1[i]+arr2[i]+carry)%10;
        carry = (arr1[i]+arr2[i]+carry)/10;
    }
    if(carry)
        temp[len++] = 1;
    for(int i = 0;i < len+1;i++){
        arr1[i] = arr2[i];
        arr2[i] = temp[i];
    }
}
int main(){
    int i = 0;
    arr1[0] = 1;arr2[1] = 1;
    while(len < 1000){
        add();i++;
    }
    cout<<i;
}
