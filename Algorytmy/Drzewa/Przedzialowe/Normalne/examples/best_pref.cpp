/*
this code will find the maximum prefix sum in a range [l, r]
*/

#include <bits/stdc++.h>
using namespace std;

#define cerr if(1) cout
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;

// now in segment tree we will keep pair{sum, res = max pref sum on this range}

typedef pair<ll, ll> node; // {sum, max pref sum}

class SegmentTree {
private:
    node *tree;
    int n;
    node NEUTRAL;
    function<node(node, node)> op;

    void update(int v, int start, int end, int idx, node val) {
        if (start == end) {
            tree[v] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * v, start, mid, idx, val);
            } else {
                update(2 * v + 1, mid + 1, end, idx, val);
            }
            tree[v] = op(tree[2 * v], tree[2 * v + 1]);
        }
    }

    node query(int v, int start, int end, int l, int r) {
        if (r < l) {
            return NEUTRAL;
        }
        if (l == start && end == r) {
            return tree[v];
        }

        int mid = (start + end) / 2;
        return op(query(2 * v, start, mid, l, min(r, mid)),
                  query(2 * v + 1, mid + 1, end, max(l, mid+1), r));
    }

    void build(const vector<node>& tab, int v, int start, int end) {
        if (start == end) {
            tree[v] = tab[start];
        } else {
            int mid = (start + end) / 2;
            build(tab, 2 * v, start, mid);
            build(tab, 2 * v + 1, mid + 1, end);
            tree[v] = op(tree[2 * v], tree[2 * v + 1]);
        }
    }

public:
    SegmentTree(int n, node _neutral) : n(n), NEUTRAL(_neutral) {
        tree = new node[4 * n];
        fill(tree, tree + 4 * n, _neutral);
    }

    SegmentTree(const vector<node>& tab, node _neutral, function<node(node, node)> _op) : 
        n(tab.size()), NEUTRAL(_neutral), op(_op) {
        tree = new node[4 * n];
        fill(tree, tree + 4 * n, _neutral);
        build(tab, 1, 0, n - 1);
    }

    ~SegmentTree() {
        delete[] tree;
    }
    
    void change_neutral(node _neutral) {
        NEUTRAL = _neutral;
        fill(tree, tree + 4 * n, _neutral);
    }
    void change_op(function<node(node, node)> _op) {
        op = _op;
    }
  
    //? update(idx, val) - update value at idx to val
    void update(int idx, node val) {
        update(1, 0, n - 1, idx, val);
    }

    //? query(l, r) - query op in range [l, r]
    node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
    
    


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<node> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].fst;
        a[i].snd = max(0ll, a[i].fst);
    }
    SegmentTree st(a, {0, 0}, 
        [](node a, node b) -> node {
            return {
                a.fst + b.fst, 
                max(a.snd, a.fst + b.snd)
            };
        }
    );


    while (q--) {
        int t; cin >> t;
        
        if (t == 1) {
            int k;
            ll v; 
            cin >> k >> v;
            st.update(k - 1, {v, max(0ll, v)});
        } else {
            int l, r; cin >> l >> r;
            cout << st.query(l - 1, r - 1).snd << '\n';
        }
    }
}