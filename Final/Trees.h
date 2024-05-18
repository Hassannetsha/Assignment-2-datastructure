#ifndef UNTITLED_TREES_H
#define UNTITLED_TREES_H

#include <iostream>
#include <cstdint>
#include "Item.h"

using namespace std;

template <typename t>
class Trees {
protected:
    t* arr;

public:
    Trees()
    {
        arr = nullptr;
    }

    virtual void addItem (const t &item) = 0;

    virtual void deleteItem (const int &index) = 0;

    virtual void displayNormal() = 0;

    virtual void displaySortByNameAscendingly() = 0;

    virtual void displaySortByNameDescendingly() = 0;

    virtual void displaySortByPriceAscendingly() = 0;

    virtual void displaySortByPriceDescendingly() = 0;
};

template <typename t>
class HeapTree : public Trees <t> {
private:
    int capacity, size, sizeofHeapSort, arrIndex, ctnDelete;
    bool max, Reverse_Max;

public:
    explicit HeapTree (const bool &max);

    void addItem (const t &item) override;

    void deleteItem (const int &index) override;

    void modifyHeapTree (const int &start);

    void heapSort (const int &node);

    bool check();

    void heapSortForDisplay();

    void displayNormal() override;

    void displaySortByNameAscendingly();

    void displaySortByNameDescendingly();

    void displaySortByPriceAscendingly();

    void displaySortByPriceDescendingly();

    ~HeapTree();
};

template <typename t>
class BinarySearchTree : public Trees <t> {
private:
    struct node {
        t data;
        node* LChild;
        node* RChild;

        node()
        {
            LChild = RChild = nullptr;
        }

        explicit node (const t &data)
        {
            this->data = data;
            LChild = RChild = nullptr;
        }
    };
    node* nameRoot;
    node* priceRoot;
    int size, capacity;

public:
    BinarySearchTree();

    void addItem (const t &item);

    void deleteItem (const int &index);

    node* searchItem (const t &item, const bool &name);

    void displayNormal();

    void ascendingInorder (node* node);

    void descendingInorder (node* node);

    void displaySortByNameAscendingly();

    void displaySortByNameDescendingly();

    void displaySortByPriceAscendingly();

    void displaySortByPriceDescendingly();
};

#endif
