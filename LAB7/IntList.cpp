#include <string>
#include <iostream>

using namespace std;

#include "IntList.h"

IntList::IntList()
{
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList()
{
    while (head)
    {
        IntNode* temp = head->next;
        delete head;
        head = temp;
    }

    head = nullptr;
    tail = nullptr;
}

void IntList::push_front(int num)
{
    IntNode* node = new IntNode(num);

    if (empty())
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
}

void IntList::pop_front()
{
    if (!empty())
    {
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            IntNode* temp = head->next; // shallow copy (member assignment)
            delete head;
            head = temp;
        }
    }
}

bool IntList::empty() const
{
    return head == nullptr;
}

const int& IntList::front() const
{
    return head->data;
}

const int& IntList::back() const
{
    return tail->data;
}

ostream& operator<<(ostream& os, const IntList& list)
{
    IntNode* firstNode = list.head;

    bool first = true;

    while (firstNode != nullptr)
    {
        if (!first)
        {
            os << ' ';
        }
        else
        {
            first = false;
        }

        os << firstNode->data;
        firstNode = firstNode->next;
    }

    return os;
}