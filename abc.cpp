#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int main()
{
    int k,i;
    string s;
    ifstream f("abc.txt");

    while(getline(f,s,'\n')){
        stringstream ss(s);
        getline(ss,s,'\t');
        i = stoi(s)-1;
        while(getline(ss,s,'\t')){
            a[i][stoi(s)-1] = 1;
        }
    }

    cin>>k;
    return 0;
}


