#include <bits/stdc++.h>
using namespace std;


class LazySegmentTree {
private:
    int *tree;
    int *lazy;
    int n;
    int NEUTRAL = 0;

    function<int(int, int)> op = [](int a, int b) { return a + b; };
    function<int(int, int)> lazy_op = [](int val, int times) { return val * times; };


    void push(int v, int start, int end) {
        if (lazy[v] != 0) {
            tree[v] = op(tree[v], lazy_op(lazy[v], (end - start + 1)));
            if (start != end) {
                lazy[2 * v] = op(lazy[2 * v], lazy[v]);
                lazy[2 * v + 1] = op(lazy[2 * v + 1], lazy[v]);
            }
            lazy[v] = 0;
        }
    }

    void update(int v, int start, int end, int l, int r, int val) {
        push(v, start, end); // push lazy[v] to children

        if (r < start || end < l) { // current segment is not in range
            return;
        }

        if (l <= start && end <= r) {
            lazy[v] = op(lazy[v], val); // current segment is fully in range
            push(v, start, end); // push lazy[v] to children
            return;
        }


        int mid = (start + end) / 2;
        update(2 * v, start, mid, l, r, val); // left segment is in range
        update(2 * v + 1, mid + 1, end, l, r, val); // right segment is in range
        tree[v] = op(tree[2 * v], tree[2 * v + 1]); // take value from children
    }

    int query(int v, int start, int end, int l, int r) {
        push(v, start, end); // push lazy[v] to children

        if (r < start || end < l) { // current segment is not in range
            return NEUTRAL;
        }

        if (l <= start && end <= r) { // current segment is fully in range
            return tree[v];
        }

        int mid = (start + end) / 2;
        return op(query(2 * v, start, mid, l, r),
                    query(2 * v + 1, mid + 1, end, l, r));
    }

    void build(const vector<int>& tab, int v, int start, int end) {
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
    LazySegmentTree(int n, int _neutral=0) : n(n), NEUTRAL(_neutral) {
        tree = new int[4 * n];
        fill(tree, tree + 4 * n, _neutral);

        lazy = new int[4 * n];
        fill(lazy, lazy + 4 * n, 0);
    }

    LazySegmentTree(const vector<int>& tab, int _neutral=0) : n(tab.size()), NEUTRAL(_neutral) {
        tree = new int[4 * n];
        fill(tree, tree + 4 * n, _neutral);

        lazy = new int[4 * n];
        fill(lazy, lazy + 4 * n, 0);

        build(tab, 1, 0, n - 1);
    }

    ~LazySegmentTree() {
        delete[] tree;
        delete[] lazy;
    }
    
    void change_neutral(int _neutral) {
        NEUTRAL = _neutral;
        fill(tree, tree + 4 * n, _neutral);
    }
    void change_op(function<int(int, int)> _op, function<int(int, int)> _lazy_op) {
        op = _op;
        lazy_op = _lazy_op;
    }
    
    //? update(idx, val) - update value at idx to val
    void update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }

    //? query(l, r) - query op in range [l, r]
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};