#include <iostream>

using namespace std;

#include "SortedSet.h"
#include "IntList.h"

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet& s) : IntList(s) {}

SortedSet::SortedSet(const IntList& l) : IntList(l)
{
    selection_sort();
    remove_duplicates();
}

SortedSet::~SortedSet() { this->IntList::~IntList(); }

bool SortedSet::in(int data) const
{
    IntNode* node = head;

    while (node && node->data <= data)
    {
        if (node->data == data)
        {
            return true;
        }

        node = node->next;
    }

    return false;
}

const SortedSet SortedSet::operator|(const SortedSet& set) const
{
    SortedSet result;

    IntNode* node = head;
    while (node)
    {
        result.add(node->data);
        node = node->next;
    }

    node = set.head;
    while (node)
    {
        result.add(node->data);
        node = node->next;
    }

    return result;
}

const SortedSet SortedSet::operator&(const SortedSet& set) const
{
    SortedSet result;
    IntNode* node = head;

    while (node)
    {
        if (set.in(node->data))
        {
            // don't need to call add
            result.IntList::push_back(node->data);
        }
        node = node->next;
    }

    return result;
}

void SortedSet::add(int data)
{
    if (!in(data))
    {
        IntList::insert_ordered(data);
    }
}

void SortedSet::push_front(int data)
{
    add(data);
}

void SortedSet::push_back(int data)
{
    add(data);
}

void SortedSet::insert_ordered(int data)
{
    add(data);
}

const SortedSet SortedSet::operator|=(const SortedSet& set)
{
    if (this == &set)
    {
        return *this;
    }

    IntNode* node = set.head;

    while (node != nullptr)
    {
        this->add(node->data);
        node = node->next;
    }

    return *this;
}

const SortedSet SortedSet::operator&=(const SortedSet& set)
{
    if (this == &set)
    {
        return *this;
    }

    SortedSet result(*this);
    clear();
    IntNode* node = result.head;

    while (node)
    {
        if (set.in(node->data))
        {
            // don't need to call add
            IntList::push_back(node->data);
        }
        node = node->next;
    }

    return *this;
}