#include<iostream>
#include"C:\Users\DELL\Desktop\General Store\Node.h"
using namespace std;
template <class T>
 
class LinkedList
{
	protected:
		Node<T> *head;
		Node<T> *tail;
	public:
		LinkedList()
		{
			head=tail=0;
		}
        
        Node<T>* findMid();
		Node<T>* getHead();
		Node<T>* getTail();
        void addToHead(T element);
        void addToTail(T element);
        void removeFromHead();
        void removeFromTail();
        void removeGivenNode(T element);
        void addAfter(T existElement,T newValue);
        Node<T>* search(T element);
        void traverse();
 };
 
template <class T>
Node<T>* LinkedList<T>::findMid(){
  int count;
  Node<T>* ptr= head;
  while (ptr!=0){
    count++;
    ptr=ptr->getNext();
  }
  Node<T>* ptr0=head;
  for (T i = 0; i < count/2; i++)
  {
    ptr0=ptr0->getNext();
  }
  
  cout<<"Vslue is: "<<ptr0->getInfo()<<endl;
  return ptr0;
  
}
 template <class T>
 Node<T>* LinkedList<T>::getHead()
 {
 	return this->head;
 }
 template <class T>
 Node<T>* LinkedList<T>::getTail()
 {
 	return this->tail;
 }
  template <class T>
 void LinkedList<T>::addToTail(T element){

     Node<T> *n=new Node<T>(element);

     if (this->head == 0 && this->tail == 0) {
         head = tail = n;
     } else {
         tail->setNext(n);
         tail = n;
     }
 }

template <class T>
void LinkedList<T>::traverse(){
	Node<T> *ptr=head;
	while(ptr!=0){
		cout<<ptr->getInfo()<<endl;
		ptr=ptr->getNext();
	}
}

template <class T>
void LinkedList<T>::addToHead(T element){

    Node<T> *n=new Node<T>(element);
     if (this->head == 0 && this->tail == 0) {
        head = tail = n;
    } else {
        Node<T>* ptr=head;
        head=n;
        head->setNext(ptr);
    }
   
    
}

template <class T>
Node<T>* LinkedList<T>::search(T element) {
    Node<T>* current = head;
    while (current) {
        if (current->getInfo() == element) {
            return current;
        }
        current = current->getNext();
    }
    cout<<"Value didn't find!!"<<endl;
    return nullptr;
}
template <class T>
void LinkedList<T>::removeGivenNode(T val) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    // If the node to delete is the head
    if (head->getData() == val) {
        Node<T>* ptr = head;
        head = head->getNextAddress();
        delete ptr;
        return;
    }

    // If the node to delete is the tail
    if (tail->getData() == val) {
        Node<T>* ptr = head;
        // Loop until ptr is at the node just before the tail
        while (ptr->getNextAddress() != tail) {
            ptr = ptr->getNextAddress();
        }
        delete tail;
        tail = ptr;
        tail->setNextAddress(nullptr);  // Update the new tail's next to nullptr
        return;
    }

    // If the node to delete is somewhere in the middle
    Node<T>* ptr = head;
    while (ptr->getNextAddress() != nullptr) {
        if (ptr->getNextAddress()->getData() == val) {
            Node<T>* delPtr = ptr->getNextAddress();
            ptr->setNextAddress(delPtr->getNextAddress());  // Bypass the node to delete
            delete delPtr;  // Delete the node
            return;
        }
        ptr = ptr->getNextAddress();
    }

    cout << "Value couldn't match!" << endl;  // Value not found in the list
}
