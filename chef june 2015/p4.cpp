#include<iostream>
#define ld long double
using namespace std;
ld area(ld T1,ld T2,ld t1,ld t2){
    if(T2>=t1+T1)    return T1*t1;
    else if(T2>=T1&&T2<=t1)    return (T2-0.5*T1)*T1;
    else if(T2>=T1&&T2>=t1)    return T1*t1-0.5*(T1-T2+t1)*(T1-T2+t1);
    else if(T2<=T1&&T2<=t1)    return 0.5*T2*T2;
    else if(T2<=T1&&T2>=t1)    return t1*(T2-0.5*t1);
}
int main(){
    ld T1,T2,t1,t2,T,total,ans;int k;
    cin>>T;
    while(T--){
        cin>>T1>>T2>>t1>>t2;
        total=T1*T2;
        if(T1==0&&T2==0)    cout<<1<<endl;
        else{
             cout<<(area(T1,T2,t1,t2)+area(T2,T1,t2,t1))/total<<endl;
        }
    }
}
