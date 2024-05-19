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
void BinarySearchTree <t> ::displayToDelete()
{
    cout<<"\nItems registered:\n";
    for (int i = 0; i < size; i++)
    {
        string str = to_string(i+1);
        str += ". ";
        cout<<left <<setw(5) <<str <<this->arr[i] <<'\n';
    }
}

template <typename t>
void BinarySearchTree <t> :: removeNode (BinarySearchTree :: node* &node)
{
    BinarySearchTree<t>::node* current;
    BinarySearchTree<t>::node* prev;
    BinarySearchTree<t>::node* temp;
    if (node->LChild == nullptr && node->RChild == nullptr)
    {
        delete node;
        node = nullptr;
    }
    else if (node->LChild == nullptr)
    {
        temp = node;
        node = node->RChild;
        delete temp;
    }
    else if (node->RChild == nullptr)
    {
        temp = node;
        node = node->LChild;
        delete temp;
    }
    else
    {
        current = node->LChild;
        prev = nullptr;
        while (current->RChild != nullptr)
        {
            prev = current;
            current = current->RChild;
        }
        node->data = current->data;
        if(prev == nullptr)
            node->LChild = current->LChild;
        else
            prev->RChild = current->LChild;
        delete current;
    }
}

template <typename t>
void BinarySearchTree <t> :: deleteItem (const int &index)
{
    if (index < 1 || index > size)
    {
        cerr<<"\nInvalid number!\n";
        return;
    }

    t item = this->arr[index-1];
    node* current = nameRoot;
    while (current != nullptr)
    {
        if (current->data == item)
            removeNode(current);
        else if (current->data < item)
            current = current->RChild;
        else
            current = current->LChild;
    }

    t item2 = item;
    item2.changeSortTechnique();
    current = priceRoot;
    while (current != nullptr)
    {
        if (current->data == item2)
            removeNode(current);
        else if (current->data < item2)
            current = current->RChild;
        else
            current = current->LChild;
    }

    for (int i = index-1; i < size-1; i++)
    {
        this->arr[i] = this->arr[i+1];
    }
    size--;
    cout<<"\nItem deleted successfully!\n";
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

template <typename t>
BinarySearchTree <t> :: ~BinarySearchTree()
{
    delete nameRoot;
    delete priceRoot;
}
