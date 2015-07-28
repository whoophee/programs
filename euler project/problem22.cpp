#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<string> vs;
int val(string p){
    int c = 0;
    for(string::iterator it = p.begin();it != p.end();++it){
        c += 1+(*it-'A');
    }
    return c;
}
int main(){
    string s;
    int t = 1;ll sum = 0;
    ifstream f("problem22.txt");
    while(!f.eof()){
        getline(f,s,',');
        string t(s,1,s.length()-2);
        vs.push_back(t);
    }
    sort(vs.begin(),vs.end());

    for(vector<string>::iterator it = vs.begin();it != vs.end();++it){
        sum += t*val(*it);t++;
    }
    cout<<sum;
}
