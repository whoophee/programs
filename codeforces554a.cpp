#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char s[21];
    cin>>s;
    int i,len = strlen(s),total = 26,contin = 0,counter = 26;
    for(i=1;i<=len;i++)    total += 25;
    cout<<total;
}
