#include <iostream>

using namespace std;

#include "IntVector.h"

void printVector(IntVector &);
void test1();
void test2();

int main()
{
    test1();
    test2();

    return 0;
}

void printVector(IntVector &v)
{
    if (v.empty())
    {
        cout << "Vector is empty.";
    }
    else
    {
        for (unsigned i = 0; i < v.size(); ++i)
        {
            cout << v.at(i) << " ";
        }
    }
}

void test1()
{
    cout << "Declaring IntVector with constructor arguments (10, 5)." << endl;
    IntVector vect(10, 5);

    cout << "Size: " << vect.size() << endl;
    cout << "Capacity: " << vect.capacity() << endl;

    cout << "Contents: ";
    printVector(vect);
    cout << endl;

    cout << "Front: " << vect.front() << endl;
    cout << "Back: " << vect.back() << endl;

    cout << endl;

    cout << "Declaring IntVector with default constructor." << endl;
    IntVector vect_ = IntVector();

    cout << "Size: " << vect_.size() << endl;
    cout << "Capacity: " << vect_.capacity() << endl;

    cout << "Contents: ";
    printVector(vect_);
    cout << endl;

//     cout << "Front: " << vect_.front() << endl;
//     cout << "Back: " << vect_.back() << endl;

    cout << endl;

    cout << "Test 1 completed." << endl;
}

void test2()
{
    cout << "Declaring IntVector with constructor arguments (5, 5)." << endl;
    IntVector vect(5, 5);

    cout << "Size: " << vect.size() << endl;
    cout << "Contents: ";
    printVector(vect);
    cout << endl;

    cout << "Testing out of bounds .at() call." << endl;
    cout << "vect.at(5)" <<  vect.at(5) << endl;

    cout << endl;

    cout << "Test 2 completed." << endl;
}