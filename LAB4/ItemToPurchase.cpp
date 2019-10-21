#include <string>

using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() : itemName("Unnamed"), itemPrice(-1), itemQuantity(-1) {
    return;
}

void ItemToPurchase::SetName(const string newName) {
    this->itemName = newName;
}

string ItemToPurchase::GetName() const {
    return this->itemName;
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