#include <iostream>

using namespace std;

#include "IntList.h"

void program5Tests(IntList&);

int main() {

    //tests constructor, destructor, push_front, pop_front, display

    {
        cout << "\nlist1 constructor called" << endl;
        IntList list1;
        cout << "pushfront 10" << endl;
        list1.push_front(10);
        cout << "pushfront 20" << endl;
        list1.push_front(20);
        cout << "pushfront 30" << endl;
        list1.push_front(30);
        cout << "list1: " << list1 << endl;
        cout << "pop" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
        cout << "pop" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
        cout << "pop" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
        cout << "pushfront 100" << endl;
        list1.push_front(100);
        cout << "pushfront 200" << endl;
        list1.push_front(200);
        cout << "pushfront 300" << endl;
        list1.push_front(300);
        cout << "list1: " << list1 << endl;
        cout << endl;
        cout << "Calling list1 destructor..." << endl;
    }
    cout << "list1 destructor returned" << endl;

    // Test destructor on empty IntList
    {
        IntList list2;
        cout << "Calling list2 destructor..." << endl;
    }
    cout << "list2 destructor returned" << endl;

    // Testing PROGRAM5 functions
    cout << endl;
    cout << "Declaring new IntList" << endl;
    IntList list;
    cout << "Running tests:" << endl;
    program5Tests(list);

    return 0;
}

void program5Tests(IntList &list)
{
    cout << "List contents: " << list << endl;

    cout << "Adding 5 via pushfront" << endl;
    list.push_front(5);
    cout << "List contents: " << list << endl;

    cout << "Adding 3 via pushfront" << endl;
    list.push_front(3);
    cout << "List contents: " << list << endl;

    cout << "Adding 1 via pushback" << endl;
    list.push_back(1);
    cout << "List contents: " << list << endl;

    cout << "Using selection sort" << endl;
    list.selection_sort();
    cout << "List contents: " << list << endl;

    cout << "clear()" << endl;
    list.clear();
    cout << "clear() returned" << endl;

    cout << "Adding 1 via pushfront" << endl;
    list.push_front(1);
    cout << "List contents: " << list << endl;

    cout << "Adding 3 via pushback" << endl;
    list.push_back(3);
    cout << "List contents: " << list << endl;

    cout << "Adding 4 via pushfront" << endl;
    list.push_front(4);
    cout << "List contents: " << list << endl;

    cout << "Adding 2 via pushback" << endl;
    list.push_back(2);
    cout << "List contents: " << list << endl;

    cout << "Adding 5 via pushfront" << endl;
    list.push_front(5);
    cout << "List contents: " << list << endl;

    cout << "Using selection sort" << endl;
    list.selection_sort();
    cout << "List contents: " << list << endl;

    cout << "Inserting 6 ordered" << endl;
    list.insert_ordered(6);
    cout << "List contents: " << list << endl;

    cout << "Inserting 4 ordered" << endl;
    list.insert_ordered(4);
    cout << "List contents: " << list << endl;

    cout << "Inserting 0 ordered" << endl;
    list.insert_ordered(0);
    cout << "List contents: " << list << endl;

    cout << "Inserting 9 ordered" << endl;
    list.insert_ordered(9);
    cout << "List contents: " << list << endl;

    cout << "Inserting 0 ordered" << endl;
    list.insert_ordered(0);
    cout << "List contents: " << list << endl;

    cout << "Inserting 0 ordered" << endl;
    list.insert_ordered(0);
    cout << "List contents: " << list << endl;

    cout << "Inserting 9 ordered" << endl;
    list.insert_ordered(9);
    cout << "List contents: " << list << endl;

    cout << "Adding 5 via pushfront" << endl;
    list.push_front(5);
    cout << "List contents: " << list << endl;

    cout << "Adding 5 via pushfront" << endl;
    list.push_front(5);
    cout << "List contents: " << list << endl;

    cout << "Adding 5 via pushfront" << endl;
    list.push_front(5);
    cout << "List contents: " << list << endl;

    cout << "Using selection sort" << endl;
    list.selection_sort();
    cout << "List contents: " << list << endl;

    cout << "Removing duplicates" << endl;
    list.remove_duplicates();
    cout << "List contents: " << list << endl;

    cout << "Testing = operator overloading" << endl;
    IntList list2 = list;
    cout << "List 2 contents: " << list2 << endl;

    cout << "Testing copy constructor" << endl;
    IntList list3(list);
    cout << "List 3 contents: " << list3 << endl;

    cout << "Declaring new list with some elements" << endl;
    IntList list4;
    for (int i = 0; i < 20; ++i)
    {
        list4.push_front(i);
    }
    cout << "List 4 contents: " << list4 << endl;

    cout << "Making list3 equal list 4 w = operator" << endl;
    list3 = list4;
    cout << "List 3 contents: " << list3 << endl;

    cout << "TESTS COMPLETED!" << endl;
}