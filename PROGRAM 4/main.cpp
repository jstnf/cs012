#include <iostream>

using namespace std;

#include "IntVector.h"

void printVector(const IntVector&);

void performAllTests(IntVector&);

void testInsertion(IntVector&);
void testErase(IntVector&);
void testResize(IntVector&);
void testPushPop(IntVector&);
void testFrontBack(const IntVector&);
void testLoopModifyValues(IntVector&);
void testReserve(IntVector&);
void testClear(IntVector&);

int main()
{
    cout << "Declaring IntVector with constructor arguments (10, 5)." << endl;
    IntVector vect(10, 5);

    performAllTests(vect);

    cout << endl;

    cout << "Declaring IntVector with default constructor." << endl;
    IntVector vect_ = IntVector();

    performAllTests(vect_);

    cout << endl;

    cout << "Declaring IntVector with constructor arguments (5, 5)." << endl;
    IntVector _vect(5, 5);

    cout << "Size: " << _vect.size() << endl;
    cout << "Contents: ";
    printVector(_vect);
    cout << endl;

    cout << "Testing out of bounds .at() call." << endl;
    cout << ".at(5)" << _vect.at(5) << endl;

    cout << endl; 
    
    return 0;
}

void printVector(const IntVector& v)
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

void performAllTests(IntVector& vect)
{
    testInsertion(vect);
    testErase(vect);
    testPushPop(vect);
    testResize(vect);
    testFrontBack(vect);
    testLoopModifyValues(vect);
    testReserve(vect);
    testClear(vect);
}

void testInsertion(IntVector& vect)
{
    cout << " --- TEST .insert() --- " << endl;
    cout << "Contents (before): ";
    printVector(vect);
    cout << endl;
    cout << "Inserting 9001 at 0" << endl;
    vect.insert(0, 9001);
    cout << "Inserting 1009 at sz - 1" << endl;
    vect.insert(vect.size() - 1, 1009);
    cout << "Contents (after): ";
    printVector(vect);
    cout << endl;
}

void testErase(IntVector& vect)
{
    cout << " --- TEST .erase() --- " << endl;
    cout << "Contents (before): ";
    printVector(vect);
    cout << endl;
    cout << "Erasing element at vect.size() / 2" << endl;
    vect.erase(vect.size() / 2);
    cout << "Contents (after): ";
    printVector(vect);
    cout << endl;
}

void testResize(IntVector& vect)
{
    cout << " --- TEST .resize() --- " << endl;
    cout << "Contents (before): ";
    printVector(vect);
    cout << endl;
    cout << "Resizing to size 6, value 3." << endl;
    vect.resize(6, 3);
    cout << "Size: " << vect.size() << endl;
    cout << "Capacity: " << vect.capacity() << endl;
    cout << "Contents (after): ";
    printVector(vect);
    cout << endl;
}

void testPushPop(IntVector& vect)
{
    cout << " --- TEST .push_back() & .pop_back() --- " << endl;
    cout << "Contents (before): ";
    printVector(vect);
    cout << endl;
    cout << "push_back(9)" << endl;
    vect.push_back(9);
    cout << "Contents: ";
    printVector(vect);
    cout << endl;
    cout << "pop_back()" << endl;
    vect.pop_back();
    cout << "Contents: ";
    printVector(vect);
    cout << endl;
}

void testFrontBack(const IntVector& vect)
{
    cout << " --- TEST .front() & .back() --- " << endl;
    cout << "Contents: ";
    printVector(vect);
    cout << endl;
    cout << "FRONT: " << vect.front() << endl;
    cout << "BACK:  " << vect.back() << endl;
}

void testLoopModifyValues(IntVector& vect)
{
    cout << " --- TEST .at() = something --- " << endl;
    cout << "Contents (before): ";
    printVector(vect);
    cout << endl;
    cout << "Assigning each element in the vector to its position index." << endl;
    for (unsigned i = 0; i < vect.size(); ++i)
    {
        vect.at(i) = i * 2;
        cout << "vect.at(" << i << ") = " << i << " * 2;" << endl;
    }
    cout << "Contents (after): ";
    printVector(vect);
    cout << endl;
}

void testReserve(IntVector& vect)
{
    cout << " --- TEST .reserve() --- " << endl;
    cout << "vect.size(): " << vect.size() << endl;
    cout << "vect.capacity(): " << vect.capacity() << endl;
    cout << "Attempting reserve of 1 element." << endl;
    vect.reserve(1);
    cout << "vect.size(): " << vect.size() << endl;
    cout << "vect.capacity(): " << vect.capacity() << endl;
    cout << "Attempting reserve of 1234 elements." << endl;
    vect.reserve(1234);
    cout << "vect.size(): " << vect.size() << endl;
    cout << "vect.capacity(): " << vect.capacity() << endl;
}

void testClear(IntVector& vect)
{
    cout << " --- TEST .clear() --- " << endl;
    cout << "Contents (before): ";
    printVector(vect);
    cout << endl;
    cout << "Clearing the vector with .clear()." << endl;
    vect.clear();
    cout << "vect.empty(): ";
    if (vect.empty())
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    cout << "vect.size(): " << vect.size() << endl;
    cout << "vect.capacity(): " << vect.capacity() << endl;
}