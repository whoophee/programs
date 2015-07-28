#include<iostream>
#include<string>
#define ll long long
#define MOD 1000000007
using namespace std;

ll comb[5001][5001],a[5001];
int init_nCr(){
    int i,j;
    for(i = 0; i < 5001; i++)
        comb[i][0] = comb[0][i] = comb[i][i] = 1;
    for(i = 1; i < 5001; i++)
        for(j = 1; j < i; j++)
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
}
struct trie{
    ll val;
    char letter;
    trie *next[26];
}*root,*iterate,*temp;
int init(trie *t,char k){
    int i;
    t->val=0;t->letter=k;
    for(i=0;i<26;i++)t->next[i]=NULL;
}
int add_substr(string k){
    iterate=root;ll i,h;
    for(i=0;i<=5000;i++)a[i]=0;
    for(i=0;i<k.length();i++){
        a[iterate->val]--;
        iterate->val++;
        a[iterate->val]++;
        cout<<k[i]<<" "<<iterate->val<<endl;
        h=k[i]-'a';
        if(iterate->next[h]==NULL){
            temp = new trie();
            iterate->next[h] = temp;
            init(iterate->next[h],h);
        }
        iterate=iterate->next[h];
    }
}

int main(){
    ll t,n,q,i,j;root=new trie();iterate=new trie();
    init(root,' ');
    string c,tempo;
    init_nCr();
    cin>>t;
    while(t--){
        cin>>n>>q;
        cin>>c;
        for(j=0;j<n;j++){
            tempo.assign(c,j,n-j);
            add_substr(tempo);
        }
    }
}
