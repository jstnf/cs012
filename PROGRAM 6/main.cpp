#include <iostream>

using namespace std;

#include "SortedSet.h"
#include "IntList.h"

int main()
{
    cout << "Declaring odds and evens IntLists" << endl;
    IntList* odds = new IntList();
    IntList* evens = new IntList();

    for (int i = 1; i < 10; ++i)
    {
        odds->push_front(i * 2 - 1);
        evens->push_front(i * 2);
    }

    cout << "IntList evens: " << *evens << endl;
    cout << "IntList odds: " << *odds << endl;

    cout << "Declaring empty SortedSet oddSet and evenSet" << endl;

    SortedSet* oddSet = new SortedSet();
    SortedSet* evenSet = new SortedSet();

    cout << "SortedSet evenSet: " << *evenSet << endl;
    cout << "SortedSet oddSet: " << *oddSet << endl;

    cout << "Deleting oddSet and evenSet" << endl;

    delete evenSet;
    delete oddSet;

    cout << "Delete returned" << endl;

    cout << "Using SortedSet(IntList) constructor" << endl;

    oddSet = new SortedSet(*odds);
    evenSet = new SortedSet(*evens);

    cout << "SortedSet evenSet: " << *evenSet << endl;
    cout << "SortedSet oddSet: " << *oddSet << endl;

    cout << "Is 5 in oddSet?: " << oddSet->in(5) << endl;
    cout << "Is 5 in evenSet?: " << evenSet->in(5) << endl;

    cout << "Is 6 in oddSet?: " << oddSet->in(6) << endl;
    cout << "Is 6 in evenSet?: " << evenSet->in(6) << endl;

    cout << "Adding 5 to oddSet" << endl;
    oddSet->add(5);
    cout << "SortedSet oddSet: " << *oddSet << endl;

    cout << "Adding 6 to oddSet" << endl;
    oddSet->add(6);
    cout << "SortedSet oddSet: " << *oddSet << endl;

    cout << "Declaring IntList* pointed to oddSet called oddSetPointer" << endl;
    IntList* oddSetPointer = oddSet;
    cout << "oddSetPointer->push_front(8)" << endl;
    oddSetPointer->push_front(8);
    cout << "oddSetPointer->push_back(10)" << endl;
    oddSetPointer->push_back(10);
    cout << "oddSetPointer->insert_ordered(12)" << endl;
    oddSetPointer->insert_ordered(12);
    cout << "SortedSet oddSet: " << *oddSetPointer << endl;

    cout << "Resetting oddSet to match odds w/ SortedSet constructor" << endl;
    cout << "Declaring new SortedSet from odds" << endl;
    SortedSet* temp = new SortedSet(*odds);
    cout << "SortedSet temp: " << *temp << endl;
    cout << "Deleting oddSet" << endl;
    delete oddSet;
    cout << "Using SortedSet(SortedSet) constructor" << endl;
    oddSet = new SortedSet(*temp);
    cout << "SortedSet oddSet: " << *oddSet << endl;

    cout << "Testing union | operator" << endl;
    cout << "Making a new SortedSet from union of oddSet and evenSet" << endl;
    SortedSet united = *evenSet | *oddSet;
    cout << "SortedSet united: " << united << endl;

    cout << "Testing intersection & operator" << endl;
    cout << "Making a new SortedSet from intersection of oddSet and evenSet" << endl;
    SortedSet intersected = *evenSet & *oddSet;
    cout << "SortedSet intersected: " << intersected << endl;

    cout << "Testing self union" << endl;
    cout << "SortedSet selfUnited = *oddSet | *oddSet" << endl;
    SortedSet selfUnited = *oddSet | *oddSet;
    cout << "SortedSet selfUnited: " << selfUnited << endl;

    cout << "Testing self intersection" << endl;
    cout << "SortedSet selfInterSected = *oddSet & *oddSet" << endl;
    SortedSet selfIntersected = *oddSet & *oddSet;
    cout << "SortedSet selfIntersected: " << selfUnited << endl;

    cout << "Testing = operator" << endl;
    SortedSet oddSetEquals = *oddSet;
    cout << "SortedSet oddSetEquals: " << oddSetEquals << endl;

    SortedSet oddSetTemp = SortedSet(*oddSet);
    cout << "SortedSet oddSetTemp = " << oddSetTemp << endl;
    SortedSet evenSetTemp = SortedSet(*evenSet);
    cout << "SortedSet evenSetTemp = " << evenSetTemp << endl;

    cout << "Testing union-assign |= operator" << endl;
    cout << "*oddSetTemp |= *evenSetTemp: " << (oddSetTemp |= evenSetTemp) << endl;

    cout << "Testing intersection-assign &= operator" << endl;
    cout << "*oddSetTemp &= *temp: " << (oddSetTemp &= evenSetTemp) << endl;

    return 0;
}