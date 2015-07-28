#include<iostream>
#include<algorithm>
#define BIGINT long long
using namespace std;
BIGINT a[20],counter,n,x;
int check(int i,BIGINT l,BIGINT r,BIGINT max,BIGINT min,bool prev){
    if(l <= 0 && r >=0 && max-min >=x && prev)    counter++;
    if(i == n || r < 0)    return 0;
    check(i+1,l-a[i],r-a[i],(a[i]>max)?a[i]:max,(a[i]<min)?a[i]:min,true);
    check(i+1,l,r,max,min,false);
}
int main(){
    BIGINT l,r,i;
    cin>>n>>l>>r>>x;
    for(i = 0;i < n;i++)cin>>a[i];
    check(0,l,r,0,1000000001,true);
    cout<<counter;
    cin>>i;
}
