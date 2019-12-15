#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
    int data;
    IntNode* next;
    IntNode(int data) : data(data), next(0) { }
};

class IntList {
protected:
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
    IntList(const IntList&);
    IntList& operator=(const IntList&);
    // PROGRAM5 functions
    void push_back(int);
    void clear();
    void selection_sort();
    void insert_ordered(int);
    void remove_duplicates();
};

#endif