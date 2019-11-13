#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
    int data;
    IntNode* next;
    IntNode(int data) : data(data), next(nullptr) { }
};

class IntList {
private:
    IntNode* head;
    IntNode* tail;
public:
    IntList();
    ~IntList();
    void push_front(int);
    void pop_front();
    bool empty() const;
    const int& front() const;
    const int& back() const;
    friend ostream& operator<<(ostream&, const IntList&);
};

#endif