#include <vector>

using namespace std;

#include "ItemToPurchase.h"

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

class ShoppingCart {
	public:
	  ShoppingCart();
	  ShoppingCart(const string, const string);
	  string GetCustomerName() const;
	  string GetDate() const;
      void AddItem(const ItemToPurchase&);
	  void RemoveItem(const string);
	  void ModifyItem(const ItemToPurchase&);
	  int GetNumItemsInCart() const;
	  int GetCostOfCart() const;
	  void PrintTotal() const;
	  void PrintDescriptions() const;
	private:
	  string customerName;
	  string currentDate;
	  vector<ItemToPurchase> cartItems;
};

#endif