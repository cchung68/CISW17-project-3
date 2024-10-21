#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu()
{
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
}

void ExecuteMenu(char option, ShoppingCart& theCart)
{
    string name, description;
    int price, quantity, newQuantity;

    cin.ignore();

    if (option == 'a')
    {
        cout << "ADD ITEM TO CART" << endl;

        cout << "Enter the item name:" << endl;
        getline(cin, name);

        cout << "Enter the item description:" << endl;
        getline(cin, description);


        cout << "Enter the item price:" << endl;
        cin >> price;

        cout << "Enter the item quantity:" << endl;
        cin >> quantity;
        cout << endl;

        ItemToPurchase newItem(name, description, price, quantity);
        theCart.AddItem(newItem);
    }
    else if (option == 'd')
    {
        cout << "REMOVE ITEM FROM CART" << endl;

        cout << "Enter name of item to remove:" << endl;
        getline(cin, name);
        theCart.RemoveItem(name);
        cout << endl;
    }
    else if (option == 'c')
    {
        cout << "CHANGE ITEM QUANTITY" << endl;

        cout << "Enter the item name:" << endl;
        getline(cin, name);

        cout << "Enter the new quantity:" << endl;
        cin >> newQuantity;
        cin.ignore();

        ItemToPurchase modifiedItem;
        modifiedItem.SetName(name);
        modifiedItem.SetQuantity(newQuantity);
        theCart.ModifyItem(modifiedItem);
        cout << endl;
    }
    else if (option == 'i')
    {
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;

        theCart.PrintDescriptions();
        cout << endl;
    }
    else if (option == 'o')
    {
        cout << "OUTPUT SHOPPING CART" << endl;

        theCart.PrintTotal();
    }
}

int main() {
    string custName;
    string today;
    char menuChoice;

    menuChoice = ' ';

    cout << "Enter customer's name:" << endl;
    getline(cin, custName);
    cout << "Enter today's date:" << endl;
    getline(cin, today);
    cout << endl;
    cout << "Customer name: " << custName << endl;
    cout << "Today's date: " << today << endl << endl;

    ShoppingCart myCart(custName, today);

    PrintMenu();

    while (menuChoice != 'q') {
        cout << "Choose an option:" << endl;
        cin >> menuChoice;

        if (menuChoice == 'a' || menuChoice == 'd' || menuChoice == 'c' ||
            menuChoice == 'i' || menuChoice == 'o') {
            ExecuteMenu(menuChoice, myCart);
            PrintMenu();
        }
        else if (menuChoice != 'q')
        {
            cout << "Choose an option:";
            cin >> menuChoice;
            cout << endl;
        }
    }

    return 0;
}