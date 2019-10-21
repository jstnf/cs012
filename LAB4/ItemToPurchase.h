using namespace std;

#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

class ItemToPurchase {
    public:
      ItemToPurchase();
      void SetName(const string);
      string GetName() const;
      void SetPrice(const int);
      int GetPrice() const;
      void SetQuantity(const int);
      int GetQuantity() const;
    private:
      string itemName;
      int itemPrice;
      int itemQuantity;
};

#endif