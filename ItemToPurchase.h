#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, int price, int quantity);
    void SetName(string name);
    string GetName() const;
    void SetDescription(string description);
    string GetDescription() const;
    void SetPrice(int price);
    int GetPrice() const;
    void SetQuantity(int quantity);
    void SetNewQuantity(int newQuantity);
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
