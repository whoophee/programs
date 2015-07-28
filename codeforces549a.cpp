#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int m,n,i,j,counter = 0,arr[4];
    cin>>n>>m;
    char b[n][m];
    for(i = 0;i < n;i++)
        cin>>b[i];
    for(i = 1;i < n;i++)
    for(j = 1;j < m;j++){
        arr[0] = b[i][j]-'a';arr[1] = b[i-1][j-1]-'a';arr[2] = b[i-1][j]-'a';arr[3] = b[i][j-1]-'a';
        sort(arr,arr+4);
        if(arr[0] == 0 && arr[1] == 2 && arr[2] == 4 && arr[3] == 5)counter++;
    }
    cout<<counter;
    cin>>i;
}
