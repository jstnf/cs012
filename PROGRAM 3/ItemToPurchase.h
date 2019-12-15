using namespace std;

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

class ItemToPurchase {
    public:
      ItemToPurchase();
	  ItemToPurchase(const string, const string, const int, const int);
      void SetName(const string);
      string GetName() const;
	  void SetDescription(const string);
	  string GetDescription() const;
      void SetPrice(const int);
      int GetPrice() const;
      void SetQuantity(const int);
      int GetQuantity() const;
	  void PrintItemCost() const;
	  void PrintItemDescription() const;
    private:
      string itemName;
	  string itemDescription;
      int itemPrice;
      int itemQuantity;
};

#endif