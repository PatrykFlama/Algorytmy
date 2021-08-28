//! KMP
//? https://themis.ii.uni.wroc.pl/2021IIAGIMROZ/KMP
#include<bits/stdc++.h>
using namespace std;
const int L = 2e6+15; //max string lenghts
int pi[L];
string w, t;
vector<int> ans;


void compute_pi(string s, int n){
    int len = 0;
    pi[0] = 0;

    for(int i = 0; i < n-1; i++){
        int j = pi[i];
        while(j > 0 && s[i+1] != s[j])
            j = pi[j-1];
        if(s[i+1] == s[j])
            j++;
        pi[i+1] = j;
        if(pi[i+1] == w.size())
            ans.push_back(i-w.size()-w.size()+1);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while(T--){
        cin >> w >> t;     //wzorzec, tekst
        int n = t.size()+w.size()+1;
        compute_pi(w+'#'+t, n);

        for(int i : ans)
            cout << i << ' ';
        cout << '\n';

        ans.clear();
    }

    return 0;
}
