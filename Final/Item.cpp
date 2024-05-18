#include "Item.h"

using namespace std;

Item :: Item (const string &itemName, const string &category, const double &price)
{
    name = true;
    this->itemName = itemName;
    this->category = category;
    this->price = price;
}

bool Item :: operator < (const Item &item)
{
    if (!reverse)
    {
        if (name)
        {
            string name1 = this->itemName;
            string name2 = item.itemName;
            transform(name1.begin(), name1.end(), name1.begin(), [](unsigned char c) {return tolower(c);});
            transform(name2.begin(), name2.end(), name2.begin(), [](unsigned char c) {return tolower(c);});
            return name1 < name2;
        }
        else
        {
            return this->price < item.price;
        }
    }
    else
    {
        return this->operator > (item);
    }
}

bool Item :: operator > (const Item &item)
{
    if (reverse)
    {
        if (this->name)
        {
            string name1 = this->itemName;
            string name2 = item.itemName;
            transform(name1.begin(), name1.end(), name1.begin(), [](unsigned char c) {return tolower(c);});
            transform(name2.begin(), name2.end(), name2.begin(), [](unsigned char c) {return tolower(c);});
            return name1 > name2;
        }
        else
        {
            return this->price > item.price;
        }
    }
    else
    {
        return this->operator < (item);
    }
}

bool Item :: operator <= (const Item &item)
{
    if (name)
    {
        string name1 = this->itemName;
        string name2 = item.itemName;
        transform(name1.begin(), name1.end(), name1.begin(), [](unsigned char c) {return tolower(c);});
        transform(name2.begin(), name2.end(), name2.begin(), [](unsigned char c) {return tolower(c);});
        return name1 <= name2;
    }
    else
    {
        return this->price <= item.price;
    }
}

bool Item :: operator >= (const Item &item)
{
    if (name)
    {
        string name1 = this->itemName;
        string name2 = item.itemName;
        transform(name1.begin(), name1.end(), name1.begin(), [](unsigned char c) {return tolower(c);});
        transform(name2.begin(), name2.end(), name2.begin(), [](unsigned char c) {return tolower(c);});
        return name1 >= name2;
    }
    else
    {
        return this->price >= item.price;
    }
}

bool Item :: operator == (const Item &item)
{
    return this->itemName == item.itemName && this->category == item.category && this->price == item.price;
}

bool Item :: operator != (const Item &item)
{
    return this->itemName != item.itemName && this->category != item.category && this->price != item.price;
}

void Item :: changeSortTechnique()
{
    name ^= 1;
}

void Item :: descending (const bool &yes)
{
    reverse = yes;
}

ostream& operator << (ostream &os, const Item &item)
{
    os<<"Name: " <<left <<setw(20) <<item.itemName <<"Price: " <<left <<setw(10) <<item.price <<"Category: "<< item.category;
    return os;
}
