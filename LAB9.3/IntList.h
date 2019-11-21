#ifndef __INTLIST_H__
#define __INTLIST_H__

#include <ostream>

using namespace std;

struct IntNode
{
    int data;
    IntNode* next;
    IntNode(int data) : data(data), next(0) {}
};


class IntList
{
private:
    IntNode* head;

public:
    /* Initializes an empty list.
    */
    IntList();

    /* Inserts a data value to the front of the list.
    */
    void push_front(int);

    /* Outputs to a single line all of the int values stored in the list, each separated by a space.
       This function does NOT output a newline or space at the end.
    */
    friend ostream& operator<<(ostream&, const IntList&);

    /* Returns true if the integer passed in is contained within the IntList.
       Otherwise returns false.
    */
    bool exists(int) const;

private:
    /* Helper function that returns true if the integer passed in is contained within
       the IntNodes starting from the IntNode whose address is passed in.
       Otherwise returns false.
    */
    bool exists(IntNode*, int) const;
};

/* Helper function that passes in the address of a IntNode within an IntList and outputs
   all of integers within the IntList starting from this IntNode.
*/
ostream& operator<<(ostream&, IntNode*);

#endif