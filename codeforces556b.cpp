#include<iostream>
using namespace std;
int main(){
    int n,k,x,i,a = 0;char ans[2][4]={"Yes","No"};
    cin>>n;
    cin>>k;
    for(i = 1;i < n;i++){
        cin>>x;
        if(i%2 == 1){
            if((x+k)%n != i){a = 1;break;}
        }
        else{
            if(x-k > 0 && (x-k) != i){a = 1;break;}
            if(x-k <= 0 && (n+x-k) != i){a = 1;break;}
        }
    }
    cout<<ans[a];
}
