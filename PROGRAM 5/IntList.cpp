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
            IntNode* temp = head->next; // member assignment
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

IntList::IntList(const IntList &cpy)
{
    if (cpy.empty())
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        for (IntNode* nodeToCopy = cpy.head; nodeToCopy != nullptr; nodeToCopy = nodeToCopy->next)
        {
            push_back(nodeToCopy->data);
        }
    }
}

IntList& IntList::operator=(const IntList &rhs)
{
    IntList list(rhs);

    if (list.empty())
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        clear();
        for (IntNode* nodeToCopy = list.head; nodeToCopy != nullptr; nodeToCopy = nodeToCopy->next)
        {
            push_back(nodeToCopy->data);
        }
    }

    return *this;
}

void IntList::push_back(int num)
{
    IntNode* node = new IntNode(num);

    if (empty())
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}

void IntList::clear()
{
    while (!empty())
    {
        pop_front();
    }
}

void IntList::selection_sort()
{
    if (!empty())
    {
        for (IntNode* sortNode = head; sortNode->next != nullptr; sortNode = sortNode->next)
        {
            IntNode* minNode = sortNode;
            for (IntNode* selectNode = sortNode->next; selectNode != nullptr; selectNode = selectNode->next)
            {
                if (selectNode->data < minNode->data)
                {
                    minNode = selectNode;
                }
            }

            int temp = sortNode->data;
            sortNode->data = minNode->data;
            minNode->data = temp;
        }
    }
}

void IntList::insert_ordered(int num)
{
    if (empty())
    {
        head = new IntNode(num);
        tail = head;
    }
    else
    {
        IntNode* nodeToInsert = new IntNode(num);
        IntNode* prevNode = nullptr;
        IntNode* nextNode = head;
        while (nextNode != nullptr && num > nextNode->data)
        {
            prevNode = nextNode;
            nextNode = nextNode->next;
        }

        if (prevNode == nullptr)
        {
            nodeToInsert->next = head;
            head = nodeToInsert;
        }
        else
        {
            prevNode->next = nodeToInsert;
        }

        if (nextNode == nullptr)
        {
            if (prevNode != nullptr)
            {
                tail->next = nodeToInsert;
            }
            tail = nodeToInsert;
        }
        else
        {
            nodeToInsert->next = nextNode;
        }
    }
}

void IntList::remove_duplicates()
{
    for (IntNode* check = head; check != nullptr && check->next != nullptr; check = check->next)
    {
        for (IntNode* against = check; against != nullptr && against->next != nullptr; against = against->next)
        {
            while (against->next != nullptr && against->next->data == check->data)
            {
                IntNode* temp = against->next;
                against->next = against->next->next;
                if (temp == tail)
                {
                    tail = against;
                }
                delete temp;
            }
        }
    }
}

ostream& operator<<(ostream& os, const IntList& list)
{
    IntNode* node = list.head;
    bool first = true;

    while (node != nullptr)
    {
        if (!first)
        {
            os << " ";
        }
        else
        {
            first = false;
        }

        os << node->data;
        node = node->next;
    }

    return os;
}