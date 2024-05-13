#ifndef ASSIGNMENT_2_DATASTRUCTURE_TREES_H
#define ASSIGNMENT_2_DATASTRUCTURE_TREES_H
#include "Item.h"
template<typename t>
class Trees{
protected:
    struct node {
        node *LChild;
        int data;
        int Height;
        node *RChild;
    };
    node *root;
    t *arr;
public:
    Trees();
    virtual void Add_item(const t& item) = 0;
    virtual void Delete_item(const int& index_to_delete) = 0;
    virtual void Display_normal() = 0;
    virtual void Display_sort_by_name_ascending() = 0;
    virtual void Display_sort_by_name_descending() = 0;
    virtual void Display_sort_by_price_ascending() = 0;
    virtual void Display_sort_by_price_descending() = 0;
};

template<typename t>
Trees<t>::Trees() {
    root = nullptr;
    arr = nullptr;
}

#endif