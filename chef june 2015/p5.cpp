#include<iostream>
#include<map>
#include<string>
#define ll long long
#define MOD 1000000007
using namespace std;
ll comb[5001][5001];
int main(){
    ll n,q,t,i,j,a[5001],k,sum;
    string c,temp;
    map <string,int> m;
    map <string,int>::iterator it;
    for(i = 0; i < 5001; i++)
        comb[i][0] = comb[0][i] = comb[i][i] = 1;
    for(i = 1; i < 5001; i++)
        for(j = 1; j < i; j++)
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
    cin>>t;
    while(t--){
        cin>>n>>q;
        cin>>c;
        for(i=0;i<n;i++)
        for(j=1;j<=n-i;j++){
            temp.assign(c,i,j);
            if(m.find(temp)==m.end()){
                m[temp]=1;
            }
            else    m[temp]++;
        }
        while(q--){
            sum=0;
            cin>>k;
            if(k<5000)
            for(it=m.begin();it!=m.end();++it){
                if(k<=it->second)sum+=comb[it->second][k];
            }
            cout<<sum<<endl;
        }
        m.clear();
    }
}
