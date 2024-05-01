#include <bits/stdc++.h>
using namespace std;


template <class T>
class Stack {
    struct Node {
        T val;
        Node* next;
    };

    Node* head;
    unsigned int _size;

public:
    Stack() {
        head = nullptr;
        _size = 0;
    }

    T top() {
        if(head) {
            return head->val;
        } else {
            throw new out_of_range("Stack is empty");
        }
    }

    void push(T val) {
        head = new Node{val, head};
        _size++;
    }

    void pop() {
        if(head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            _size--;
        } else {
            throw new out_of_range("Stack is empty");
        }
    }

    unsigned int size() {
        return _size;
    }

    bool empty() {
        return _size == 0;
    }
};


int main() {}