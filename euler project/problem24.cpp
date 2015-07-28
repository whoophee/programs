#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[] = {0,1,2,3,4,5,6,7,8,9};
int b[] = {362880,40320,5040,720,120,24,6,2,1,1};
int ans[10];
int nthperm(int a,int index){
    if(index == 10)
        return 0;
    int i = 0,remain = a%b[index],v = (a/b[index]);
    cout<<v<<endl;
    while(1){
        if(arr[i] != -1){
            if(v == 0)
                break;
            v--;
        }
        i++;
    }
    ans[index] = i;
    arr[i] = -1;
    nthperm(remain,index+1);
}
int main(){
    nthperm(1000000-1,0);
    for(int i = 0;i < 10;i++)
        cout<<ans[i];
}
