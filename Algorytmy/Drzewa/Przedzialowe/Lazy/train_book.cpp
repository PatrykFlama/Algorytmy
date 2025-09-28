/*
this code is a solution to the problem of booking seats in a train compartment  
for each query, it checks if the requested number of seats can be booked in the specified range
*/

#include <bits/stdc++.h>
using namespace std;

#define cerr if(1) cout
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;


struct Node {
    int max_val;

    Node(int max_val = 0) : max_val(max_val) {}

    bool operator==(const Node& other) const {
        return max_val == other.max_val;
    }
    bool operator!=(const Node& other) const {
        return !(*this == other);
    }
};

class LazySegmentTree {
private:
    vector<Node> tree;
    vector<Node> lazy;
    int n;
    Node NEUTRAL;

    //? applied to children, to calculate parent
    function<Node(const Node&, const Node&)> op;
    //? lazy_op(node, lazy val) - applies lazy value to node 
    function<Node(const Node&, const Node&)> lazy_op;

    void push(int v, int start, int end) {
        if (lazy[v] != NEUTRAL) {
            if (start != end) {
                lazy[2 * v] = lazy_op(lazy[2 * v], lazy[v]);
                lazy[2 * v + 1] = lazy_op(lazy[2 * v + 1], lazy[v]);
            }

            tree[v] = lazy_op(tree[v], lazy[v]);
            lazy[v] = NEUTRAL;
        }
    }

    void update(int v, int start, int end, int l, int r, Node val) {
        push(v, start, end);

        if (r < start || end < l)
            return;

        if (l <= start && end <= r) {
            lazy[v] = lazy_op(lazy[v], val);
            push(v, start, end);
            return;
        }

        int mid = (start + end) / 2;
        update(2 * v, start, mid, l, r, val);
        update(2 * v + 1, mid + 1, end, l, r, val);
        tree[v] = op(tree[2 * v], tree[2 * v + 1]);
    }

    Node query(int v, int start, int end, int l, int r) {
        push(v, start, end);

        if (r < start || end < l)
            return NEUTRAL;

        if (l <= start && end <= r)
            return tree[v];

        int mid = (start + end) / 2;
        return op(
            query(2 * v, start, mid, l, r),
            query(2 * v + 1, mid + 1, end, l, r)
        );
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
    LazySegmentTree(int n, Node _neutral,
                    function<Node(const Node&, const Node&)> _op, function<Node(const Node&, const Node&)> _lazy_op) :
                n(n), NEUTRAL(_neutral), op(_op), lazy_op(_lazy_op) {
        tree.assign(4 * n, _neutral);
        lazy.assign(4 * n, _neutral);
    }

    LazySegmentTree(const vector<Node>& tab, Node _neutral,
                    function<Node(const Node&, const Node&)> _op, function<Node(const Node&, const Node&)> _lazy_op) :
                n(tab.size()), NEUTRAL(_neutral), op(_op), lazy_op(_lazy_op) {
        tree.assign(4 * n, _neutral);
        lazy.assign(4 * n, _neutral);
        build(tab, 1, 0, n - 1);
    }

    //? update(l, r, val) - add val to range [l, r]
    void update(int l, int r, Node val) {
        update(1, 0, n - 1, l, r, val);
    }

    //? query(l, r) - query with op function
    Node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};




int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q; cin >> n >> m >> q;

    LazySegmentTree st(n+1, {0},
        [](const Node& a, const Node& b) {
            return Node{ max(a.max_val, b.max_val) };
        },
        [](const Node& val, const Node& lazy_val) {
            return Node{ val.max_val + lazy_val.max_val };
        }
    );

    while (q--) {
        int _from, _to, _seats; cin >> _from >> _to >> _seats;
        _to--;


        Node res = st.query(_from, _to);
        if (res.max_val + _seats <= m) {
            st.update(_from, _to, {_seats});
            cout << "T\n";
        } else {
            cout << "N\n";
        }
    }
}