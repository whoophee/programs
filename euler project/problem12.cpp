#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int i,t,n,j;
    int counter = 1;
    map<int,int> a;
    for(i = 1;;i++){
        a.clear();
        counter = 1;
        n = (i*(i+1))/2;
        t = n;
        for(j = 2;j < sqrt(t);j++){
            if(n == 1)
                break;
            if(n%j == 0){
                if(a.find(j) == a.end())
                    a[j] = 0;
                a[j] = a[j]+1;
                n = n/j;
                j--;
            }
        }
        for(map<int,int>::iterator it = a.begin();it != a.end();it++){
            counter *= (it->second+1);
        }
        if(counter >= 500)
            break;
    }
    cout<<i<<endl;
    cout<<t;
}
