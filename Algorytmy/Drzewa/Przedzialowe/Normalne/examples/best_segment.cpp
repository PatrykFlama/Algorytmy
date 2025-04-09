/*
this code will find the maxium sum of contiguous subarray in a range [l, r]
*/

#include <bits/stdc++.h>
using namespace std;

#define cerr if(1) cout
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;

// now in segment tree we will keep pair{sum, res = max pref sum on this range}

class Node {
public:
    ll sum, pref_sum, suff_sum, max_sum;
    Node() : sum(0), pref_sum(0), suff_sum(0), max_sum(0) {}
    Node(ll _sum, ll _pref_sum, ll _suff_sum, ll _max_sum) : 
        sum(_sum), pref_sum(_pref_sum), suff_sum(_suff_sum), max_sum(_max_sum) {}
};

class SegmentTree {
private:
    Node *tree;
    int n;
    Node NEUTRAL;
    function<Node(Node, Node)> op;

    void update(int v, int start, int end, int idx, Node val) {
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

    Node query(int v, int start, int end, int l, int r) {
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

    void build(const vector<Node>& tab, int v, int start, int end) {
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
    SegmentTree(int n, Node _neutral) : n(n), NEUTRAL(_neutral) {
        tree = new Node[4 * n];
        fill(tree, tree + 4 * n, _neutral);
    }

    SegmentTree(const vector<Node>& tab, Node _neutral, function<Node(Node, Node)> _op) : 
        n(tab.size()), NEUTRAL(_neutral), op(_op) {
        tree = new Node[4 * n];
        fill(tree, tree + 4 * n, _neutral);
        build(tab, 1, 0, n - 1);
    }

    ~SegmentTree() {
        delete[] tree;
    }
    
    void change_neutral(Node _neutral) {
        NEUTRAL = _neutral;
        fill(tree, tree + 4 * n, _neutral);
    }
    void change_op(function<Node(Node, Node)> _op) {
        op = _op;
    }
  
    //? update(idx, val) - update value at idx to val
    void update(int idx, Node val) {
        update(1, 0, n - 1, idx, val);
    }

    //? query(l, r) - query op in range [l, r]
    Node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
    
    


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<Node> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].sum;
        a[i].pref_sum = a[i].suff_sum = a[i].max_sum = max(a[i].sum, 0ll);
    }

    SegmentTree st(a, Node(0ll, 0ll, 0ll, 0ll),
        [](Node a, Node b) -> Node {
            return {
                a.sum + b.sum,
                max(a.pref_sum, a.sum + b.pref_sum),
                max(b.suff_sum, b.sum + a.suff_sum),
                max({a.max_sum, b.max_sum, a.suff_sum + b.pref_sum})
            };
        }
    );


    while (q--) {
        int k; ll x; cin >> k >> x;
        k--;

        ll max_sum = max(x, 0ll);
        st.update(k, Node(x, max_sum, max_sum, max_sum));
        
        Node res = st.query(0, n - 1);
        cout << res.max_sum << '\n';
    }
}