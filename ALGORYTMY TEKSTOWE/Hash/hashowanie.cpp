//! hashowanie
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7, x = 27;


int create_hash(string s){
    int hash = 0;

    for(char c : s){
        //   = (to long long * prev polynomial * x to increase degree of pol * letter const) % modulo to decrease bignum
        hash = (1LL * hash * x + (c - 'a' + 1)) % MOD;
    }

    return hash;
}


int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    string s; cin >> s;
    cout << create_hash(s) << '\n';

    return 0;
}
