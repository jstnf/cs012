#include <iostream>

using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void mainMenu(ShoppingCart&);
void selector(ShoppingCart&);

int main() {
	ShoppingCart cart;
	string name;
	string date;
	
	cout << "Enter customer's name:" << endl;
	getline(cin, name);
	cout << "Enter today's date:" << endl;
	getline(cin, date);
	cout << endl;
	
	cart = ShoppingCart(name, date);
	cout << "Customer name: " << cart.GetCustomerName() << endl;
	cout << "Today's date: " << cart.GetDate() << endl;
	cout << endl;
	
	mainMenu(cart);
    return 0;
}

void mainMenu(ShoppingCart& sc) {
	cout << "MENU" << endl;
	cout << "a - Add item to cart" << endl;
	cout << "d - Remove item from cart" << endl;
	cout << "c - Change item quantity" << endl;
	cout << "i - Output items' descriptions" << endl;
	cout << "o - Output shopping cart" << endl;
	cout << "q - Quit" << endl;
	cout << endl;
	selector(sc);
}

void selector(ShoppingCart& sc) { // Separate menu and selection to make invalid choice work according to specs.
	cout << "Choose an option:" << endl;
	
	string choice;
	cin >> choice;
	cin.ignore();
	
	if (choice == "a") {
		string name;
		string desc;
		int price;
		int quantity;
		
		cout << "ADD ITEM TO CART" << endl;
		cout << "Enter the item name:" << endl;
		getline(cin, name);
		cout << "Enter the item description:" << endl;
		getline(cin, desc);
		cout << "Enter the item price:" << endl;
		cin >> price;
		cout << "Enter the item quantity:" << endl;
		cin >> quantity;
		ItemToPurchase toAdd(name, desc, price, quantity);
		
		sc.AddItem(toAdd);
		cout << endl;
		mainMenu(sc);
	}
	else if (choice == "d") {
		string toRemove;
		
		cout << "REMOVE ITEM FROM CART" << endl;
		cout << "Enter name of item to remove:" << endl;
		getline(cin, toRemove);
		
		sc.RemoveItem(toRemove);
		mainMenu(sc);
	}
	else if (choice == "c") {
		string name;
		int quantity;
		
		cout << "CHANGE ITEM QUANTITY" << endl;
		cout << "Enter the item name:" << endl;
		getline(cin, name);
		cout << "Enter the new quantity:" << endl;
		cin >> quantity;
		
		ItemToPurchase mod(name, "", 0, quantity);
		sc.ModifyItem(mod);
		mainMenu(sc);
	}
	else if (choice == "i") {
		cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
		sc.PrintDescriptions();
		mainMenu(sc);
	}
	else if (choice == "o") {
		cout << "OUTPUT SHOPPING CART" << endl;
		sc.PrintTotal();
		mainMenu(sc);
	}
	else if (choice == "q") {
		// Do nothing!
	}
	else {
		selector(sc);
	}
}