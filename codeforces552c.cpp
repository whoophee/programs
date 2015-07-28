# include <iostream>
using namespace std;
long long we[100];
long long w, m;
bool ispossible(long long m, long long i) {
     
    if(i == 0 && m <= 1)
        return true;
    else if(i == 0)
        return false;
        
    bool ans1 = false;
    if(m < we[i]) {
         
        if(m <= 2*we[i-1])
            return ispossible(m, i-1);
        if(m >= we[i] - 2*we[i-1])
            return ispossible(we[i] - m, i-1);
        return false;
        
    }
    return ispossible(m-we[i], i-1);
}
int main() {
    cin >> w >> m;
    long long i,j;
    we[0] = 1;
    long long m1 = m;
    for(i = 1; i < 100; i++) {
        we[i] = we[i-1]*w;
        if(we[i] >= m) {
            break;
        }
    }
    if(w == 2 || w == 3)
        cout << "YES" << endl;
    else if(ispossible(m, i))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
