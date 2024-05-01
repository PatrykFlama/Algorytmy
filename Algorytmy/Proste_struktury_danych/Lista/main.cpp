#include <bits/stdc++.h>
using namespace std;

template<class T>
class Node {
    T val;
    Node *next, *prev;

public:
    Node(T _val) : Node(_val, nullptr, nullptr) {};
    Node(T _val, Node* _next, Node* _prev) :
        val(_val), next(_next), prev(_prev) {};
};

template<class T>
class List {
    Node<T>* head, tail;
    unsigned int _size;

public:
    List() {
        head = tail = nullptr;
        _size = 0;
    };
    
    T front() {
        if(head) {
            return head->val;
        } else {
            throw new out_of_range("List is empty");
        }
    }

    T back() {
        if(tail) {
            return tail->val;
        } else {
            throw new out_of_range("List is empty");
        }
    }


    void push_front(T val) {
        if(head) {
            head = new Node<T>(val, head, nullptr);
            head->next->prev = head;
        } else {
            head = tail = new Node<T>(val);
        }

        _size++;
    }

    void push_back(T val) {
        if(tail) {
            tail = new Node<T>(val, nullptr, tail);
            tail->prev->next = tail;
        } else {
            head = tail = new Node<T>(val);
        }

        _size++;
    }


    void pop_front() {
        if(head) {
            Node<T>* tmp = head;
            head = head->next;
            delete tmp;
            _size--;
        } else {
            throw new out_of_range("List is empty");
        }
    }

    void pop_back() {
        if(tail) {
            Node<T>* tmp = tail;
            tail = tail->prev;
            delete tmp;
            _size--;
        } else {
            throw new out_of_range("List is empty");
        }
    }

    void clear() {
        while(head) {
            pop_front();
        }
        _size = 0;
    }

    bool empty() {
        return head == nullptr;
    }

    unsigned int size() {
        return _size;
    }

    friend ostream& operator<<(ostream& os, List<T>& list) {
        Node<T>* temp = list.head;
        while(temp) {
            os << temp->val << " ";
            temp = temp->next;
        }
        return os;
    }
};


int main() {}
