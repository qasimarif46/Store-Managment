#include <iostream>
#include "CartList.h"
#include "Item.h"
using namespace std;

CartList<Item *> cartListManuObj; // hear CartList is a ultimate linklist an <Item*> is an object's address which we are passing in cartList as an data type
CartList<Item *> cartListCartObj;
string item_ID;
int itemQuantity;
Node<Item *> *searchResult;
//  Function to show menu
int userChoice()
{
    int switchVar;
    cout << "PRESS 1 TO BUY AN ITEM: " << endl;
    cout << "PRESS 2 TO REMOVE AN ITEM FROM CART: " << endl;
    cout << "PRESS 3 TO VIEW CART: " << endl;
    cout << "PRESS 4 TO GENRATE BILL: " << endl;
    cout << "PRESS 0 TO END PROGRAM: " << endl;
    cin >> switchVar;
    return switchVar;
}
void buyItem()
{
    cout << "Enter item ID: " << endl;
    cin >> item_ID;
    cout << "Enter item quantity: " << endl;
    cin >> itemQuantity;
    searchResult = cartListManuObj.search(item_ID);
    if (searchResult)
    {
        for (int i = 0; i < itemQuantity; i++)
        {
            cartListCartObj.addToTail(new Item(searchResult->getInfo()->getItemID(), searchResult->getInfo()->getItemName(), searchResult->getInfo()->getDescription(), searchResult->getInfo()->getPrice()));
        }
        cout << itemQuantity << " " << searchResult->getInfo()->getItemName() << " added to cart: " << endl; // Assuming `getInfo` returns `Item*`
        cartListCartObj.traverse();
    }
    else
    {
        cout << "Incorrect item id!" << endl;
    }
}
void deletItem()
{
    cout << "Enter item ID: " << endl;
    cin >> item_ID;
    cartListCartObj.removeGivenNode(item_ID);
    
    cartListCartObj.traverse();

}


int main()
{
    int choiceNum;

      // Display items as a menu
        cout << "Available Items:" << endl;
        cout << "------------------------------------------" << endl;
        cout << "1. ID: A101, Name: Laptop, Description: High-performance gaming laptop, Price: $1299.99" << endl;
        cout << "2. ID: B102, Name: Smartphone, Description: Latest model with advanced features, Price: $999.99" << endl;
        cout << "3. ID: C103, Name: Headphones, Description: Noise-cancelling over-ear headphones, Price: $199.99" << endl;
        cout << "4. ID: D104, Name: Smartwatch, Description: Feature-packed smartwatch, Price: $249.99" << endl;
        cout << "5. ID: E105, Name: Backpack, Description: Durable and spacious travel backpack, Price: $89.99" << endl;
        cout << "------------------------------------------" << endl;

    // Create objects dynamically
    cartListManuObj.addToTail(new Item("A101", "Laptop", "High-performance gaming laptop", 1299.99));
    cartListManuObj.addToTail(new Item("B102", "Smartphone", "Latest model with advanced features", 999.99));
    cartListManuObj.addToTail(new Item("C103", "Headphones", "Noise-cancelling over-ear headphones", 199.99));
    cartListManuObj.addToTail(new Item("D104", "Smartwatch", "Feature-packed smartwatch", 249.99));
    cartListManuObj.addToTail(new Item("E105", "Backpack", "Durable and spacious travel backpack", 89.99));

    //   It will show a manu bar to user to select any function he wants

    choiceNum = userChoice(); // Get next choice

    while (choiceNum != 0)
    {
        switch (choiceNum)
        {
        case 1:
            buyItem();
            break;
        case 2:
            deletItem();
            break;

        case 3:
            cartListCartObj.traverse();
            break;

        case 4:
            cartListCartObj.traverse();
            cartListCartObj.generateBill();
            break;
        default:
            cout << "Invalid option" << endl;
        }
        choiceNum = userChoice();
    }

    cout << "Program has been ended successfully";
}