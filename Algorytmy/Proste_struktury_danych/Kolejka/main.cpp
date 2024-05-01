#include <bits/stdc++.h>
using namespace std;


template<class T>
class Queue {
    struct Node {
        T val;
        Node* next;
    };

    Node* head;
    Node* tail;
    unsigned int _size;

public:
    Queue() {
        head = tail = nullptr;
        _size = 0;
    }

    T front() {
        if(head) {
            return head->val;
        } else {
            throw new out_of_range("Queue is empty");
        }
    }

    T back() {
        if(tail) {
            return tail->val;
        } else {
            throw new out_of_range("Queue is empty");
        }
    }

    void push(T val) {
        if(tail) {
            tail->next = new Node{val, nullptr};
            tail = tail->next;
        } else {
            head = tail = new Node{val, nullptr};
        }

        _size++;
    }

    void pop() {
        if(head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            _size--;
        } else {
            throw new out_of_range("Queue is empty");
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