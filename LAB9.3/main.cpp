#include <iostream>

#include "IntList.h"

using namespace std;

int main()
{
    IntList test1;
    IntList test2;
    int testNum;

    cout << "Enter test number: ";
    cin >> testNum;
    cout << endl;

    // Test operator<< function
    if (testNum == 1) {
        // output empty list
        cout << "Empty : " << test1 << "T" << endl;

        // output list of size 1
        test1.push_front(3);
        cout << "Size 1: " << test1 << "T" << endl;

        // output list of size 2
        test1.push_front(0);
        cout << "Size 2: " << test1 << "T" << endl;

        // output list of size 5
        test1.push_front(-3);
        test1.push_front(8);
        test1.push_front(0);
        cout << "Size 5: " << test1 << "T" << endl;
    }

    // Test exists function
    if (testNum == 2) {

        // test on empty list
        cout << "Empty: " << test2.exists(0) << endl;

        test2.push_front(-4);

        // test on list of size 1, doesn't exist
        cout << "Size 1 (doesn't exist): " << test2.exists(-1) << endl;

        // test on list of size 1, does exist
        cout << "Size 1 (does exist): " << test2.exists(-4) << endl;

        test2.push_front(-5);
        test2.push_front(4);
        test2.push_front(0);
        test2.push_front(6); // {6 0 4 -5 -4}

        // test on list of size 5, doesnt' exist
        cout << "Size 5 (doesn't exist): " << test2.exists(1) << endl;

        // test on list of size 5, exists in head
        cout << "Size 5 (exists in head): " << test2.exists(6) << endl;

        // test on list of size 5, exists in tail
        cout << "Size 5 (exists in tail): " << test2.exists(-4) << endl;

        // test on list of size 5, exists somewhere in middle
        cout << "Size 5 (exists in middle): " << test2.exists(0) << endl;
    }

    return 0;
}