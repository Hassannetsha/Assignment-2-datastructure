#ifndef ASSIGNMENT_2_DATASTRUCTURE_ITEM_H
#define ASSIGNMENT_2_DATASTRUCTURE_ITEM_H

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Item {
    string Item_name;
    string Category;
    double Price;
    bool name, reverse;
public:
    Item(const string &, const string &, const double &);

    Item() = default;

    void change_sort_technique();

    bool operator<(const Item &);

    bool operator>(const Item &);

    bool operator<=(const Item &);

    bool operator>=(const Item &);

    bool operator==(const Item &);

    bool operator!=(const Item &item);

    void descending();

    friend ostream &operator<<(ostream &os, const Item &Item_to_print);
};

Item::Item(const string &Item_name, const string &Category, const double &Price) {
    reverse = false;
    name = true;
    this->Item_name = Item_name;
    this->Category = Category;
    this->Price = Price;
}

bool Item::operator<(const Item &item) {
    if (!reverse) {
        if (name) {
            string name1 = this->Item_name;
            string name2 = item.Item_name;
            transform(name1.begin(), name1.end(), name1.begin(), [](unsigned char c) { return std::tolower(c); });
            transform(name2.begin(), name2.end(), name2.begin(), [](unsigned char c) { return std::tolower(c); });
            return name1 < name2;
        } else {
            return this->Price < item.Price;
        }
    } else {
        return this->operator>(item);
    }
}

bool Item::operator>(const Item &item) {
    if (this->name) {
        string name1 = this->Item_name;
        string name2 = item.Item_name;
        transform(name1.begin(), name1.end(), name1.begin(), [](unsigned char c) { return std::tolower(c); });
        transform(name2.begin(), name2.end(), name2.begin(), [](unsigned char c) { return std::tolower(c); });
        return name1 > name2;
    } else {
        return this->Price > item.Price;
    }
}

bool Item::operator<=(const Item &item) {
    if (name) {
        string name1 = this->Item_name;
        string name2 = item.Item_name;
        transform(name1.begin(), name1.end(), name1.begin(), [](unsigned char c) { return std::tolower(c); });
        transform(name2.begin(), name2.end(), name2.begin(), [](unsigned char c) { return std::tolower(c); });
        return name1 <= name2;
    } else {
        return this->Price <= item.Price;
    }
}

bool Item::operator>=(const Item &item) {
    if (name) {
        string name1 = this->Item_name;
        string name2 = item.Item_name;
        transform(name1.begin(), name1.end(), name1.begin(), [](unsigned char c) { return std::tolower(c); });
        transform(name2.begin(), name2.end(), name2.begin(), [](unsigned char c) { return std::tolower(c); });
        return name1 >= name2;
    } else {
        return this->Price >= item.Price;
    }
}

bool Item::operator==(const Item &item) {
    return this->name == item.name && this->Category == item.Category && this->Price == item.Price;
}

ostream &operator<<(ostream &os, const Item &Item_to_print) {
    os << Item_to_print.Category << " " << Item_to_print.Item_name << " " << Item_to_print.Price;
    return os;
}

bool Item::operator!=(const Item &item) {
    return this->name != item.name && this->Category != item.Category && this->Price != item.Price;
}

void Item::change_sort_technique() {
    name ^= 1;
}


void Item::descending() {
    reverse ^= 1;
}


#endif
