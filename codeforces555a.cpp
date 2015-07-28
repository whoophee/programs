#include <iostream>
using namespace std;
int main(){
    int n,k,i,m,x,total = 0;
    cin>>n>>k;
    int t = 0,prev = 1;
    for(i = 0;i < k;i++){
        cin>>m;
        total += m-1;t = 0;
        while(m--){
            cin>>x;
            if(x == 1)    t = 1;
            else if(t == 1 && x == prev+1){
                prev++;total -= 2;
            }
        }
    }
    cout<<total+(n-1);
    cin>>n;
}
