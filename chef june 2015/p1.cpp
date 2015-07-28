#include<iostream>
using namespace std;
int main(){
    long long int t,a,p,i,s;
    cin>>t;
    while(t--){
        cin>>i;p=s=0;
        while(i--){
            cin>>a;
            if(a>p)s+=a-p;
            p=a;
        }
        cout<<s<<endl;       
    }
}
