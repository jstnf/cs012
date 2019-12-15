#ifndef __SORTEDSET_H__
#define __SORTEDSET_H__

using namespace std;

#include "IntList.h"

class SortedSet : public IntList
{
    public:
      SortedSet();
      SortedSet(const SortedSet &);
      SortedSet(const IntList &);
      ~SortedSet();
      bool in(int) const;
      const SortedSet operator|(const SortedSet &) const;
      const SortedSet operator&(const SortedSet &) const;
      void add(int);
      void push_front(int);
      void push_back(int);
      void insert_ordered(int);
      const SortedSet operator|=(const SortedSet &);
      const SortedSet operator&=(const SortedSet &);
};

#endif