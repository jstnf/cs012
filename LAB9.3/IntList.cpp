#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}

void IntList::push_front(int val)
{
    if (!head)
    {
        head = new IntNode(val);
    }
    else
    {
        IntNode* temp = new IntNode(val);
        temp->next = head;
        head = temp;
    }
}

bool IntList::exists(int val) const
{
    if (head == nullptr)
    {
        return false;
    }
    
    return exists(head, val);
}

bool IntList::exists(IntNode* node, int val) const
{
    if (node->data != val)
    {
        if (node->next == nullptr)
        {
            return false;
        }
        else
        {
            return exists(node->next, val);
        }
    }
    else
    {
        return true;
    }
}

ostream& operator<<(ostream& os, const IntList& list)
{
    if (list.head == nullptr)
    {
        return os;
    }

    os << list.head->data;
    return operator<<(os, list.head->next);
}

ostream& operator<<(ostream& os, IntNode* node)
{
    if (node == nullptr)
    {
        return os;
    }
    else
    {
        os << " ";
    }

    os << node->data;
    return operator<<(os, node->next);
}