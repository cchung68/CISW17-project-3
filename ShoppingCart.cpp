#include <iostream>
using namespace std;

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string customer, string date)
{
    customerName = customer;
    currentDate = date;
}

string ShoppingCart::GetCustomerName() const
{
    return customerName;
}

string ShoppingCart::GetDate() const
{
    return currentDate;
}

void ShoppingCart::AddItem(const ItemToPurchase& newItem)
{
    cartItems.push_back(newItem);
}

void ShoppingCart::RemoveItem(string& name)
{
    bool found = false;

    for (size_t i = 0; i < cartItems.size(); i++)
    {
        if (cartItems[i].GetName() == name)
        {
            cartItems.erase(cartItems.begin() + i);
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

void ShoppingCart::ModifyItem(ItemToPurchase& item)
{
    bool found = false;

    for (size_t i = 0; i < cartItems.size(); i++)
    {
        if (cartItems[i].GetName() == item.GetName())
        {
            if (item.GetDescription() == "none")
            {
                cartItems[i].SetDescription(item.GetDescription());
            }

            cartItems[i].SetQuantity(item.GetQuantity());

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

int ShoppingCart::GetNumItemsInCart() const
{
    int totalQuantity = 0;

    for (size_t i = 0; i < cartItems.size(); i++)
    {
        totalQuantity += cartItems[i].GetQuantity();
    }

    return totalQuantity;
}

int ShoppingCart::GetCostOfCart() const
{
    int totalCost = 0;

    for (size_t i = 0; i < cartItems.size(); i++)
    {
        totalCost += (cartItems[i].GetPrice() * cartItems[i].GetQuantity());
    }

    return totalCost;
}

void ShoppingCart::PrintTotal() const
{
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl;
    cout << endl;

    if (cartItems.empty())
    {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }

    for (size_t i = 0; i < cartItems.size(); i++)
    {
        cartItems[i].PrintItemCost();
    }

    cout << endl;
    cout << "Total: $" << GetCostOfCart() << endl;
    cout << endl;
}

void ShoppingCart::PrintDescriptions() const
{
    if (cartItems.empty())
    {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    else
    {
        cout << customerName << "'s Shopping Cart - " << currentDate << endl;
        cout << endl;
        cout << "Item Descriptions" << endl;

        for (size_t i = 0; i < cartItems.size(); i++)
        {
            cout << cartItems[i].GetName() << ": " << cartItems[i].GetDescription() << endl;
        }
    }
}