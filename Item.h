#ifndef ASSIGNMENT_2_DATASTRUCTURE_ITEM_H
#define ASSIGNMENT_2_DATASTRUCTURE_ITEM_H
#include <iostream>
using namespace std;
class Item
{
    string Item_name;
    string Category;
    double Price;
public:
    bool name;
    Item(const string&, const string&, const double&);
    bool operator<(const Item&);
    bool operator>(const Item&);
    bool operator<=(const Item&);
    bool operator>=(const Item&);
    bool operator==(const Item&);
    friend ostream& operator <<(ostream& os,const Item& Item_to_print);
};

Item::Item(const string& Item_name, const string& Category,const double& Price) {
    name = true;
    this->Item_name = Item_name;
    this->Category = Category;
    this->Price = Price;
}

bool Item::operator<(const Item & item) {
    if(name){
        return this->Item_name<item.Item_name;
    }
    else{
        return this->Price<item.Price;
    }
}

bool Item::operator>(const Item & item) {
    if(name){
        return this->Item_name>item.Item_name;
    }
    else{
        return this->Price>item.Price;
    }
}

bool Item::operator<=(const Item &item) {
    if(name){
        return this->Item_name<=item.Item_name;
    }
    else{
        return this->Price<=item.Price;
    }
}

bool Item::operator>=(const Item &item) {
    if(name){
        return this->Item_name>=item.Item_name;
    }
    else{
        return this->Price>=item.Price;
    }
}

bool Item::operator==(const Item &item) {
    if(name){
        return this->Item_name==item.Item_name;
    }
    else{
        return this->Price==item.Price;
    }
}

ostream& operator<<(ostream& os , const Item& Item_to_print) {
    os << Item_to_print.Category<<" "<<Item_to_print.Item_name<<" "<<Item_to_print.Price;
    return os;
}

#endif
