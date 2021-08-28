//! TRIE EASY
//? https://themis.ii.uni.wroc.pl/2021IIAGIMROZ/TRIESTAT
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int next[26];
    bool is_end, is_leaf;

    Node(){
        memset(next, -1, sizeof(next));
        is_end = false, is_leaf = false;
    }
};

const int L = 1e6+5;      //suma długości słów
Node nodes[L];
int nodes_cnt = 1, words_cnt = 0, leaves_cnt = 0;


void add_word(const string& s){
    int v = 0;
    for(char c : s){
        if(nodes[v].next[c-'a'] == -1){
            nodes[v].next[c-'a'] = nodes_cnt++;
            nodes[nodes[v].next[c-'a']].is_leaf = true;
            leaves_cnt++;

            if(nodes[v].is_leaf){
                leaves_cnt--;
                nodes[v].is_leaf = false;
            }
        }
        v = nodes[v].next[c-'a'];
    }

    if(!nodes[v].is_end)
        nodes[v].is_end = true, words_cnt++;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout.tie(0);

    int t; cin >> t;
    string s;
    while(t--){
        cin >> s;
        add_word(s);
    }

    cout << nodes_cnt << ' ' << leaves_cnt << ' ' << words_cnt << '\n';

    return 0;
}