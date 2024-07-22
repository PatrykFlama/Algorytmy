#include <bits/stdc++.h>
using namespace std;


/*
! memory
* 8MB for 5e4 nodes
* 160B > max node
* for ll we have 8+2*8+4 = 28B
! why avl
why not?
avl vs red-black
avl has batter constant in search operation (simply is flatter)
but red-black has amortized constant time for inserts and deletions
*/


template <class T>
class AVL {
    class Node {    //* 16B
    public:
        T val;                  //* sizeof(val)
        Node *left, *right;      //* 2*8B
        // bitset<2> / char balance;   //* ~ 1B
        int height;     // including this node      //* 4B

        Node(T _val) : Node(_val, 0, 0) {}
        Node(T _val, Node* _left, Node* _right) : 
            val(_val), left(_left), right(_right), height(1) {}
    };

    Node* root;
    T nullval;


    // ------- SMALL HELPERS --------
    inline void update_height(Node* v) {   //! not checking whole path
        v->height = max(get_height(v->left), get_height(v->right)) + 1;
    }

    inline int get_height(const Node* v) {
        return (v ? v->height : 0);
    }

    //? balance < 0 -> tree shorter on left side
    //? balance > 0 -> tree shorter on right side
    inline int balance(const Node* v) {
        if(!v) return 0;
        return get_height(v->left) - get_height(v->right);
    }

    // --------- HELPERS ----------
    // small change in conventions for rotates - the input node is parent and returned is new parent
    // also lets assume that x and y != nullptr
    Node* rotate_left(Node* x) {
        Node* y = x->right;
        Node* b = y->left;
        // Node *a = x->left, *c = y->right;      // not needed

        y->left = x;
        x->right = b;

        update_height(x);       // lower node first!!!!
        update_height(y);

        return y;   // y is the new parent
    }

    Node* rotate_right(Node* y) {
        Node* x = y->left;
        Node* b = x->right;
        // Node *a = x->left, *c = y->right;      // not needed

        y->left = b;
        x->right = y;

        update_height(y);
        update_height(x);

        return x;   // x is the new parent
    }


    void deleteTree(Node* v) {
        if(!v) return;

        // dfs for smaller memory consumption O(logn)
        deleteTree(v->left);
        deleteTree(v->right);

        delete v;
    }


    // ----------- MAIN ----------

    Node* _insert(T val, Node* v) {    // returns updated node
        if(!v) {        // create new val node at leaf
            return new Node(val);
        }
        
        // insert recursive; log(5e4) < 32 max levels of recursion
        if(val < v->val) {
            v->left = _insert(val, v->left);
        } else if(v->val < val) {
            v->right = _insert(val, v->right);
        } else return v;      // dont add val if it already exists
        update_height(v);

        // fix
        const int bal = balance(v);
        if(bal > 1) {   // tree shorter on the right side
            // that should guarantee existance of left child
            if(val < v->left->val) {    // if inserted node is on the left <=> left->left subtree is longer
                return rotate_right(v);
            } else {    // left->right longer
                v->left = rotate_left(v->left);
                return rotate_right(v);
            }
        } else if(bal < -1) {
            if(v->right->val < val) {
                return rotate_left(v);
            } else {
                v->right = rotate_right(v->right);
                return rotate_left(v);
            }
        }

        return v;
    }


    pair<Node*, bool> _remove(T val, Node* v) {     // returns updated node and if found node with val
        if(!v) {    // node was not found
            return {v, false};
        }

        // find node
        if(val < v->val) {
            const auto res = _remove(val, v->left);
            if(!res.second)   // node was not found
                return {v, false};
            v->left = res.first;
        } else if(v->val < val) {
            const auto res = _remove(val, v->right);
            if(!res.second)
                return {v, false};
            v->right = res.first;
        } else {        //! delete this node
            if(v->left && v->right) {
                // find upper bound (or lower bound) for replacement
                Node *up = v->right;
                while(up->left) {
                    up = up->left;
                }
                v->val = up->val;

                v->right = _remove(up->val, v->right).first;
            } else if(v->left) {    // only one child
                const auto temp = v->left;
                delete v;
                v = temp;
            } else {    // leaves also work here
                const auto temp = v->right;
                delete v;
                v = temp;
            }
        }
        if(!v) return {v, true};
        update_height(v);

        // fix
        const int bal = balance(v);
        if(bal > 1) {   // tree shorter on the right side
            if(balance(v->left) >= 0) {  // subtree shorter on the right side
                // (or equal since it does not matter and requires less rotations)
                return {rotate_right(v), true};
            } else {    // inner part of subtree longer
                v->left = rotate_left(v->left);
                return {rotate_right(v), true};
            }
        } else if(bal < -1) {
            if(balance(v->right) <= 0) {
                return {rotate_left(v), true};
            } else {
                v->right = rotate_right(v->right);
                return {rotate_left(v), true};
            }
        }

        return {v, true};
    }

public:
    AVL(T _nullval) : root(0), nullval(_nullval) {}
    ~AVL() {
        deleteTree(root);
        root = 0;
    }


    //? reutrns <= val
    T lower(T val) {
        // the deeper <= we find the better lower bound it is        
        Node* v = root;
        T last = nullval;
        while(v) {
            if(v->val > val) {
                v = v->left;
            } else {    // <=
                last = v->val;
                v = v->right;
            }
        }

        return last;
    }

    //? returns >= val
    T upper(T val) {
        Node* v = root;
        T last = nullval;
        while(v) {
            if(v->val < val) {
                v = v->right;
            } else {        // >=
                last = v->val;
                v = v->left;
            }
        }

        return last;
    }

    //? add val to set
    void insert(T val) {
        root = _insert(val, root);
    }

    //? delete val from set, success y/n
    bool remove(T val) {
        const auto res = _remove(val, root);
        root = res.first;
        return res.second;
    }
};


int main() {
    /*
    example program which takes [operation] [value]:
    I [value] - insert value
    D [value] - delete value
    U [value] - find upper bound
    L [value] - find lower bound
    */

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    const long long nullval = LONG_LONG_MAX;
    AVL<long long> avl(nullval);

    int t; cin >> t;
    while(t--) {
        char op; 
        long long val;
        cin >> op >> val;

        switch(op) {
            case 'I': {
                avl.insert(val);
                break;
            }
            case 'D': {
                const auto res = avl.remove(val);
                cout << (res ? "OK" : "BRAK") << '\n';
                break;
            }
            case 'U': {
                const auto res = avl.upper(val);
                if(res == nullval)
                    cout << "BRAK\n";
                else cout << res << '\n';
                break;
            }
            case 'L': {
                const auto res = avl.lower(val);
                if(res == nullval)
                    cout << "BRAK\n";
                else cout << res << '\n';
                break;
            }
        }
    }
}
