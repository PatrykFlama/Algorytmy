/*
here is a customizable segment tree (custom stored values and operation)
example below shows implementation of sum segment tree
*/

#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int sum, pref_sum, suff_sum, max_sum;
    Node() : sum(0), pref_sum(0), suff_sum(0), max_sum(0) {}
    Node(int _sum, int _pref_sum, int _suff_sum, int _max_sum) : 
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

    Node find(int v, int start, int end, function<Node(Node, Node)> &cmp) {
        if (start == end) {
            return tree[v];
        } else {
            int mid = (start + end) / 2;
            Node left = find_leaf(2 * v, start, mid, cmp);
            Node right = find_leaf(2 * v + 1, mid + 1, end, cmp);
            return cmp(left, right);
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

    //? find_leaf(cmp) - find leaf with cmp function
    Node find(function<Node(Node, Node)> cmp) {
        return find_leaf(1, 0, n - 1, cmp);
    }
};


int main() {
    int n, q; cin >> n >> q;

    SegmentTree st(n);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int idx, val; cin >> idx >> val;
            st.update(idx, Node(val, val, val, val));
        } else {
            int l, r; cin >> l >> r;
            Node res = st.query(l, r);
            cout << res.max_sum << endl;
        }
    }
}

