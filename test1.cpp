#include<bits/stdc++.h>
using namespace std;
int t,n,j,cur,f,i;char a[1000];
int main(){
    cin>>t;
    for(j = 0;j < t;j++){
        cin>>n;
        cin>>a;
        cur = a[0]-'0';f = 0;
        for(i = 1;i <= n;i++){
            if(cur < i && a[i] != '0'){
                f += i-cur;
                cur += (i+a[i])-('0'+cur);
            }
            else{
                cur += a[i]-'0';
            }
        }
        cout<<"Case #"<<j+1<<": "<<f<<endl;
    }
}
