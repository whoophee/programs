#include<iostream>
#include<algorithm>
long long int bsearch(long long int a[],long long int min,long long int max,long long int val){
     long long int mid=(max+min)/2;
     if(a[mid]!=val&&min==max)    return -1;
     else if(a[mid]>val)    return bsearch(a,min,mid-1,val);
     else if(a[mid]<val)    return bsearch(a,mid+1,max,val);
     else return mid;
}
using namespace std;
int main(){
    long long int i,t,n,k,x[100000],x1,y1,a[100000];
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>k;
            cin>>x1>>y1;k--;
            x[i]=x1;
            while(k--){
               cin>>x1>>y1;
               if(x[i]<x1)x[i]=x1;
            }
        }
        for(i=0;i<n;i++)a[i]=x[i];
        sort(a,a+n);
        for(i=0;i<n;i++){
            cout<<bsearch(a,0,n-1,x[i])<<" ";
        }
        cout<<endl;
    }
}
