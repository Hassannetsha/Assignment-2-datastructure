#ifndef UNTITLED_ITEM_H
#define UNTITLED_ITEM_H

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Item {
private:
    string itemName, category;
    double price;
    bool name;

public:
    Item() = default;

    Item (const string &itemName, const string &category, const double &price);

    bool operator < (const Item &item);

    bool operator > (const Item &item);

    bool operator <= (const Item &item);

    bool operator >= (const Item &item);

    bool operator == (const Item &item);

    bool operator != (const Item &item);

    void changeSortTechnique();

    friend ostream& operator << (ostream &os, const Item &item);
};

#endif
