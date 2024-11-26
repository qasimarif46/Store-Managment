#include<iostream>
using namespace std;

class Item{
private:   
    string item_ID;
    string itemName;
    string description;
    float price_per_item;

public:
    Item(string item_ID,string itemName,string description,float price_per_item){
      this->description=description;
      this->item_ID=item_ID;
      this->itemName=itemName;
      this->price_per_item=price_per_item;
    }
    void setItemID(string item_ID);
    void setName(string itemName);
    void setDescription(string description);
    void setPrice(float price_per_item);
    //getters
    string getItemID();
    string getItemName();
    string getDescription();
    float getPrice();  
    //fn
    void display();
};

void Item::setItemID(string item_ID){
    this->item_ID=item_ID;
}
void Item::setName(string itemName){
    this->itemName=itemName;
}
void Item::setDescription(string description){
    this->description=description;
}
void Item::setPrice(float price_per_item){
    this->price_per_item=price_per_item;
}
string Item::getItemID(){
    return item_ID;
}
string Item::getDescription(){
    return description;
}
string Item::getItemName(){
    return itemName;
}
float Item::getPrice(){
 return price_per_item;
}
void Item::display(){
    cout<<"Item name is: "<<this->itemName<<endl;
    cout<<"Item_ID is: "<<this->item_ID<<endl;
    cout<<"Item price is: "<<this->price_per_item<<endl;
    cout<<"Item description is: "<<this->description<<endl;
}
