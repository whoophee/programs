#include<iostream>
using namespace std;
int *func(){
    int i = 10;
    return &i;
}
int main(){
    int j = *(func());
    cout<<j;
    return 0;
}
