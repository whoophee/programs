#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int segment[100],k,cur,maxlen;
void addtosegment(string s){
    int carry = 0,i,len = s.length();
    cur = 0;
    for(i = len-1;i >= 0;i--){
        segment[cur] += carry + (s[i]-'0');
        carry = segment[cur]/10;
        segment[cur] = segment[cur]%10;
        cur++;
    }
    while(carry == 1){
        segment[cur] += carry;
        carry = segment[cur]/10;
        segment[cur] = segment[cur]%10;
        cur++;
    }
    if(cur > maxlen)
        maxlen = cur;
}
int main(){
    string s;
    ifstream f("problem13.txt");
    while(!f.eof()){
        f>>s;
        addtosegment(s);
    }
    for(int i = maxlen-1;i >= maxlen-10;i--){
        cout<<segment[i];
    }
}
