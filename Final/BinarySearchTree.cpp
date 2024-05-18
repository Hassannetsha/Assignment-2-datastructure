#include <iostream>
#include "Trees.h"
#include "Item.h"

using namespace std;

template <typename t>
BinarySearchTree <t> :: BinarySearchTree()
{
    nameRoot = priceRoot = nullptr;
    size = 0;
    capacity = 10;
    this->arr = new t[capacity];
}

template <typename t>
void BinarySearchTree <t> :: addItem (const t &item)
{
    if (size == capacity)
    {
        capacity *= 2;
        t* arr2 = new t[capacity];
        for (int i = 0; i < size; i++)
        {
            arr2[i] = this->arr[i];
        }
        this->arr = new t[capacity];
        this->arr = arr2;
    }
    this->arr[size] = item;

    node* current = nameRoot;
    node* prev = nullptr;
    while (current != nullptr)
    {
        prev = current;
        if (current->data < item)
            current = current->RChild;
        else
            current = current->LChild;
    }
    if (nameRoot == nullptr)
        nameRoot = new node(item);
    else if (prev->data < item)
        prev->RChild = new node(item);
    else
        prev->LChild = new node(item);

    t item2 = item;
    item2.changeSortTechnique();
    current = priceRoot;
    prev = nullptr;
    while (current != nullptr)
    {
        prev = current;
        if (current->data < item2)
            current = current->RChild;
        else
            current = current->LChild;
    }
    if (priceRoot == nullptr)
        priceRoot = new node(item2);
    else if (prev->data < item2)
        prev->RChild = new node(item2);
    else
        prev->LChild = new node(item2);

    size++;
}

template <typename t>
void BinarySearchTree <t> :: deleteItem (const int &index)
{
    if (index < 1 || index > size)
    {
        cerr<<"\nInvalid number!\n";
        return;
    }

    node* toBeDeleted = searchItem(this->arr[index-1], true);
    node* current;
    node* prev;
    node* temp;
    if (toBeDeleted->LChild == nullptr && toBeDeleted->RChild == nullptr)
    {
        delete toBeDeleted;
        toBeDeleted = nullptr;
    }
    else if (toBeDeleted->LChild == nullptr)
    {
        temp = toBeDeleted;
        toBeDeleted = toBeDeleted->RChild;
        delete temp;
    }
    else if (toBeDeleted->RChild == nullptr)
    {
        temp = toBeDeleted;
        toBeDeleted = toBeDeleted->LChild;
        delete temp;
    }
    else
    {
        current = toBeDeleted->LChild;
        prev = nullptr;
        while (current->RChild != nullptr)
        {
            prev = current;
            current = current->RChild;
        }
        toBeDeleted->data = current->data;
        if(prev == nullptr)
            toBeDeleted->LChild = current->LChild;
        else
            prev->RChild = current->LChild;
        delete current;
    }

    toBeDeleted = searchItem(this->arr[index-1], false);
    if (toBeDeleted->LChild == nullptr && toBeDeleted->RChild == nullptr)
    {
        delete toBeDeleted;
        toBeDeleted = nullptr;
    }
    else if (toBeDeleted->LChild == nullptr)
    {
        temp = toBeDeleted;
        toBeDeleted = toBeDeleted->RChild;
        delete temp;
    }
    else if (toBeDeleted->RChild == nullptr)
    {
        temp = toBeDeleted;
        toBeDeleted = toBeDeleted->LChild;
        delete temp;
    }
    else
    {
        current = toBeDeleted->LChild;
        prev = nullptr;
        while (current->RChild != nullptr)
        {
            prev = current;
            current = current->RChild;
        }
        toBeDeleted->data = current->data;
        if(prev == nullptr)
            toBeDeleted->LChild = current->LChild;
        else
            prev->RChild = current->LChild;
        delete current;
    }

    for (int i = index-1; i < size-1; i++)
    {
        this->arr[i] = this->arr[i+1];
    }
    size--;
    cout<<"\nItem deleted successfully!\n";
}

template <typename t>
typename BinarySearchTree <t> :: node* BinarySearchTree <t> :: searchItem (const t &item, const bool &name)
{
    if (name)
    {
        node* current = nameRoot;
        while (current != nullptr)
        {
            if (current->data == item)
                return current;
            if (current->data < item)
                current = current->RChild;
            else
                current = current->LChild;
        }
    }
    else
    {
        t item2 = item;
        item2.changeSortTechnique();
        node* current = priceRoot;
        while (current != nullptr)
        {
            if (current->data == item2)
                return current;
            if (current->data < item2)
                current = current->RChild;
            else
                current = current->LChild;
        }
    }
}

template <typename t>
void BinarySearchTree <t> :: displayNormal()
{
    for (int i = 0; i < size; i++)
    {
        cout<<this->arr[i] <<'\n';
    }
}

template <typename t>
void BinarySearchTree <t> :: ascendingInorder (node* node)
{
    if(node != nullptr)
    {
        ascendingInorder(node->LChild);
        cout<<node->data <<'\n';
        ascendingInorder(node->RChild);
    }
}

template <typename t>
void BinarySearchTree <t> :: descendingInorder (node* node)
{
    if(node != nullptr)
    {
        descendingInorder(node->RChild);
        cout<<node->data <<'\n';
        descendingInorder(node->LChild);
    }
}

template <typename t>
void BinarySearchTree <t> :: displaySortByNameAscendingly()
{
    ascendingInorder(nameRoot);
}

template <typename t>
void BinarySearchTree <t> :: displaySortByNameDescendingly()
{
    descendingInorder(nameRoot);
}

template <typename t>
void BinarySearchTree <t> :: displaySortByPriceAscendingly()
{
    ascendingInorder(priceRoot);
}

template <typename t>
void BinarySearchTree <t> :: displaySortByPriceDescendingly()
{
    descendingInorder(priceRoot);
}
