#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart() : customerName("none"), currentDate("January 1, 2016"), cartItems(0) {
	return;
}

ShoppingCart::ShoppingCart(const string name, const string date) {
	this->customerName = name;
	this->currentDate = date;
}

string ShoppingCart::GetCustomerName() const {
	return this->customerName;
}

string ShoppingCart::GetDate() const {
	return this->currentDate;
}

void ShoppingCart::AddItem(const ItemToPurchase& item) {
	cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(const string itemName) {
	bool found = false;
	unsigned int index = 0;
	for (unsigned i = 0; i < cartItems.size(); ++i) {
		if (cartItems.at(i).GetName() == itemName) {
			index = i;
			found = true;
			break;
		}
	}
	
	if (!found) {
		cout << "Item not found in cart. Nothing removed." << endl;
	}
	else {
		cartItems.erase(cartItems.begin() + index);
	}
	cout << endl;
}

void ShoppingCart::ModifyItem(const ItemToPurchase& item) {
	bool found = false;
	unsigned int index = 0;
	for (unsigned i = 0; i < cartItems.size(); ++i) {
		if (cartItems.at(i).GetName() == item.GetName()) {
			index = i;
			found = true;
			break;
		}
	}
	
	if (!found) {
		cout << "Item not found in cart. Nothing modified." << endl;
	}
	else {
		cartItems.at(index).SetQuantity(item.GetQuantity());
	}
	cout << endl;
}

int ShoppingCart::GetNumItemsInCart() const {
	int total = 0;
	for (unsigned i = 0; i < cartItems.size(); ++i) {
		total += cartItems.at(i).GetQuantity();
	}
	return total;
}

int ShoppingCart::GetCostOfCart() const {
	int cost = 0;
	for (unsigned i = 0; i < cartItems.size(); ++i) {
		cost += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
	}
	return cost;
}

void ShoppingCart::PrintTotal() const {
	cout << this->customerName << "'s Shopping Cart - " << this->currentDate << endl;
	cout << "Number of Items: " << GetNumItemsInCart() << endl;
	cout << endl;
	if (cartItems.size() > 0) {
		for (unsigned i = 0; i < cartItems.size(); ++i) {
			cartItems.at(i).PrintItemCost();
			cout << endl;
		}
	}
	else {
		cout << "SHOPPING CART IS EMPTY" << endl;
	}
	cout << endl;
	cout << "Total: $" << GetCostOfCart() << endl;
	cout << endl;
}

void ShoppingCart::PrintDescriptions() const {
	cout << this->customerName << "'s Shopping Cart - " << this->currentDate << endl;
	cout << endl;
	cout << "Item Descriptions" << endl;
	for (unsigned i = 0; i < cartItems.size(); ++i) {
		cartItems.at(i).PrintItemDescription();
		cout << endl;
	}
	cout << endl;
}