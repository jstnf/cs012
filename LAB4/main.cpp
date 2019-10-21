#include <iostream>

using namespace std;

#include "ItemToPurchase.h"

int main() {
    ItemToPurchase itp1;
    ItemToPurchase itp2;
    
    string currName;
    int currPrice;
    int currQuantity;
    
    cout << "Item 1" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, currName);
    cout << "Enter the item price:" << endl;
    cin >> currPrice;
    cout << "Enter the item quantity:" << endl;
    cin >> currQuantity;
    itp1.SetName(currName);
    itp1.SetPrice(currPrice);
    itp1.SetQuantity(currQuantity);
    
    cout << endl;
    cin.ignore();
    
    cout << "Item 2" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, currName);
    cout << "Enter the item price:" << endl;
    cin >> currPrice;
    cout << "Enter the item quantity:" << endl;
    cin >> currQuantity;
    itp2.SetName(currName);
    itp2.SetPrice(currPrice);
    itp2.SetQuantity(currQuantity);
    
    cout << endl;
    
    cout << "TOTAL COST" << endl;
    int itp1Price = itp1.GetPrice() * itp1.GetQuantity();
    int itp2Price = itp2.GetPrice() * itp2.GetQuantity();
    cout << itp1.GetName() << " " << itp1.GetQuantity() << " @ $" << itp1.GetPrice() << " = $" << itp1Price << endl;
    cout << itp2.GetName() << " " << itp2.GetQuantity() << " @ $" << itp2.GetPrice() << " = $" << itp2Price << endl;
    cout << endl;
    cout << "Total: $" << itp1Price + itp2Price << endl;
    
    return 0;
}