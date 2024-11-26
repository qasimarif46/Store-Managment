#include <iostream>
#include "C:\Users\DELL\Desktop\General Store\LinkedList.h"
// #include "C:\Users\DELL\Desktop\General Store\Item.h"
using namespace std;
template <class T>
class CartList : public LinkedList<T>
{
public:
    void traverse();
    Node<T> *search(string Item_ID);
    void generateBill();
    void removeGivenNode(string itemID);
};


template <class T>
void CartList<T>::traverse(){ 
    if (this->getHead() == nullptr) {
        cout << "The cart is empty!" << endl;
        return;
    }

    Node<T>* current = this->getHead();
    cout << "Items in the cart:" << endl;
    while (current != nullptr) {
        T info = current->getInfo();  // Assuming `getInfo()` returns the data (Item* in your case)
        cout << "ID: " << info->getItemID()
             << ", Name: " << info->getItemName()
             << ", Description: " << info->getDescription()
             << ", Price: $" << info->getPrice()
             << endl;
        current = current->getNext();
    }
}


template <class T>
Node<T> *CartList<T>::search(string Item_ID)
{
    Node<T> *ptr = this->getHead();
    while (ptr)
    {
        if (ptr->getInfo()->getItemID() == Item_ID)
        {
            return ptr;
        }
        ptr = ptr->getNext();
    }
    return nullptr;
}

template <class T>
void CartList<T>::removeGivenNode(string itemID)
{
    // Case 1: List is empty
    if (this->getHead() == nullptr) {
        cout << "The list is empty. No node to delete." << endl;
        return;
    }

    // Case 2: List has only one node
    if (this->getHead() == this->getTail() && this->getHead()->getInfo()->getItemID() == itemID) {
        delete this->getHead();
        this->head = this->tail = nullptr;  // Reset head and tail
        return;
    }

    // Case 3: Deleting the head node
    if (this->getHead()->getInfo()->getItemID() == itemID) {
        Node<T>* toDelete = this->getHead();
        this->head = this->getHead()->getNext();  // Move head to the next node
        delete toDelete;
        cout << "Item with ID " << itemID << " has been deleted from the list." << endl;
        return;
    }

    // Case 4: Deleting the tail node
    if (this->getTail()->getInfo()->getItemID() == itemID) {
        Node<T>* ptr = this->getHead();
        while (ptr->getNext() != this->getTail()) {
            ptr = ptr->getNext();  // Find the second-last node
        }
        delete this->getTail();  // Delete the tail
        this->tail = ptr;        // Update the tail pointer
        this->tail->setNext(nullptr);
        cout << "Item with ID " << itemID << " has been deleted from the list." << endl;
        return;
    }

    // Case 5: Deleting a node in the middle
    Node<T>* ptr = this->getHead();
    while (ptr->getNext() != nullptr && ptr->getNext()->getInfo()->getItemID() != itemID) {
        ptr = ptr->getNext();  // Traverse the list
    }

    if (ptr->getNext() != nullptr) {  // Node to delete exists
        Node<T>* toDelete = ptr->getNext();
        ptr->setNext(toDelete->getNext());  // Skip the node to delete
        cout << "Item with ID " << itemID << " has been deleted from the list." << endl;
        delete toDelete;
    } else {
        cout << "Item with ID " << itemID << " not found in the list." << endl;
    }
}


template <class T>
void CartList<T>::generateBill() {
    float totalPrice = 0;  // Initialize total price
    Node<T>* ptr = this->getHead();
    while (ptr) {
        totalPrice += ptr->getInfo()->getPrice();
        ptr = ptr->getNext();
    }
    cout << "Total bill is: $" << totalPrice << endl;
}

