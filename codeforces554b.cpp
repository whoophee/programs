#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int n,i,max=1,cur=1;
    cin>>n;
    string a[n];
    for(i = 0;i < n;i++)cin>>a[i];
    sort(a,a+n);
    for(i = 1;i < n;i++){
        if(a[i-1] == a[i])    cur++;
        else   cur = 1;
        if(cur > max) max = cur;
    }
    cout<<max;
}
