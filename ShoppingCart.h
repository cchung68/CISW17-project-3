#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart
{
public:
    ShoppingCart();
    ShoppingCart(string customer, string date);
    string GetCustomerName() const;
    string GetDate() const;
    void AddItem(const ItemToPurchase& newItem);
    void RemoveItem(string& name);
    void ModifyItem(ItemToPurchase& item);
    int GetNumItemsInCart() const;
    int GetCostOfCart() const;
    void PrintTotal() const;
    void PrintDescriptions() const;

private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
    ItemToPurchase item;
};

#endif
