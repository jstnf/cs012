#include <iostream>
#include <string>

using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() : itemName("Unnamed"), itemDescription("none"), itemPrice(0), itemQuantity(0) {
    return;
}

ItemToPurchase::ItemToPurchase(const string name, const string desc, const int price, const int quantity) {
	this->itemName = name;
	this->itemDescription = desc;
	this->itemPrice = price;
	this->itemQuantity = quantity;
}

void ItemToPurchase::SetName(const string newName) {
    this->itemName = newName;
}

string ItemToPurchase::GetName() const {
    return this->itemName;
}

void ItemToPurchase::SetDescription(const string newDescription) {
	this->itemDescription = newDescription;
}

string ItemToPurchase::GetDescription() const {
	return this->itemDescription;
}

void ItemToPurchase::SetPrice(const int newPrice) {
    this->itemPrice = newPrice;
}

int ItemToPurchase::GetPrice() const {
    return this->itemPrice;
}

void ItemToPurchase::SetQuantity(const int newQuantity) {
    this->itemQuantity = newQuantity;
}

int ItemToPurchase::GetQuantity() const {
    return this->itemQuantity;
}

void ItemToPurchase::PrintItemCost() const {
	cout << this->itemName << " " << this->itemQuantity << " @ $" << this->itemPrice << " = $" << this->itemPrice * this->itemQuantity;  
}

void ItemToPurchase::PrintItemDescription() const {
	cout << this->itemName << ": " << this->itemDescription;
}