#include<bits/stdc++.h>
using namespace std;
void blob(int a,int b){
    int c[2000],p = a,t = 0,curSize,m,l,i;
    while(p){
        t++;
        p /= 10;
    }
    curSize = t;
    t--;
    while(t >= 0){
        c[t--] = a%10;
        a /= 10;
    }
    queue<pair<int,int>> s;
    pair<int,int> p1;
    while(b--){
        m = c[0];
        l = 1;
        for(i = 1;i < curSize;i++){
            if(c[i] != m){
                p1.first = m;
                p1.second = l;
                s.push(p1);
                m = c[i];
                l = 1;
            }
            else
                l++;
        }
        p1.first = m;
        p1.second = l;
        s.push(p1);
        curSize = 0;
        while(!s.empty()){
            c[curSize] = s.front().second;
            c[curSize+1] = s.front().first;
            cout<<c[curSize]<<c[curSize+1];
            s.pop();
            curSize += 2;
        }
        cout<<endl;
    }
}
int main(){
    int a,b;
    cin>>a>>b;
    blob(a,b);
}
