#include<bits/stdc++.h>
using namespace std;
int a[200][200],b[200],i,j;
int main(){
    string s;
    ifstream f("kargerMinCut.txt");
    while(getline(f,s,'\n')){
        stringstream ss(s);
        getline(ss,s,'\t');
        i = stoi(s)-1;
        while(getline(ss,s,'\t')){
            a[i][stoi(s)-1] = 1;
        }
    }
    int sides = 0;
    ofstream op("test.txt");
    for(i = 0;i < 200;i++){
        for(j = i;j < 200;j++)
            if(a[i][j]){
                op<<"graph->edge["<<sides<<"].src = "<<i<<";\ngraph->edge["<<sides<<"].dest = "<<j<<";\n";

                sides++;
            }
    }
}
