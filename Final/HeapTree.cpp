#include <iostream>
#include "Trees.h"
#include "Item.h"

using namespace std;

template <typename t>
HeapTree <t> :: HeapTree (const bool &max)
{
    capacity = 10;
    size = ctnDelete = 0;
    arrIndex = 1;
    this->arr = new t[capacity];
    this->max = max;
    this->Reverse_Max = false;
}

template <typename t>
void HeapTree <t> :: addItem (const t &item)
{
    if (size == 0)
    {
        this->arr[arrIndex] = item;
        size++;
    }
    else if (size + 1 >= capacity)
    {
        capacity *= 2;
        t* arr2 = new t[capacity];
        for (int i = 1; i < size; i++)
        {
            arr2[i] = this->arr[i];
        }
        this->arr = new t[capacity];
        this->arr = arr2;
        this->arr[++size] = item;
        heapSort(size);
    }
    else
    {
        this->arr[++size] = item;
        heapSort(size);
    }
}

template <typename t>
void HeapTree <t> :: deleteItem (const int &index)
{
    if (index > size || index <= 0)
    {
        cerr<<"\nInvalid number!\n";
        return;
    }
    int l = 2*index, r = 2*index+1;
    if (index > size)
    {
        return;
    }
    if (l <= size && r <= size && ((this->arr[l] < this->arr[r] && !max) || (this->arr[l] > this->arr[r] && max)))
    {
        swap(this->arr[index], this->arr[l]);
        deleteItem(l);
    }
    else if (l <= size && r <= size && ((this->arr[l] > this->arr[r] && !max) || (this->arr[l] < this->arr[r] && max)))
    {
        swap(this->arr[index], this->arr[r]);
        deleteItem(r);
    }
    else
    {
        ctnDelete++;
        if (!max)
        {
            this->arr[index] = Item ("zzzzzzzzzzzzzzzzzzzz", " ", INT16_MAX);
        }
        else
        {
            this->arr[index] = Item ("aaaaaaaaaaaaaaaaaaaa", " ", INT16_MIN);
        }
        if (!check())
        {
            swap(this->arr[index], this->arr[size]);
            modifyHeapTree(index);
        }
        size--;
    }
    cout<<"\nItem deleted successfully!\n";
}

template <typename t>
void HeapTree <t> :: modifyHeapTree (const int &start)
{
    for (int i = start; i <= size; i++)
    {
        heapSort(i);
    }
}

template <typename t>
void HeapTree <t> :: heapSort (const int &node)
{
    int i = node;
    t data = this->arr[i];
    this->arr[i] = data;
    if (!max)
    {
        while (i > 1 && data < this->arr[i / 2])
        {
            this->arr[i] = this->arr[i/2];
            i /= 2;
        }
    }
    else
    {
        while (i > 1 && data > this->arr[i / 2])
        {
            this->arr[i] = this->arr[i/2];
            i /= 2;
        }
    }
    this->arr[i] = data;
}

template <typename t>
bool HeapTree <t> :: check()
{
    for (int i = 1; i < size; i++)
    {
        if ((this->arr[i] == Item("zzzzzzzzzzzzzzzzzzzz", " ", INT16_MAX) ||
             this->arr[i] == Item("aaaaaaaaaaaaaaaaaaaa", " ", INT16_MIN)) && i != size)
        {
            return false;
        }
    }
    return true;
}

template <typename t>
void HeapTree <t> :: heapSortForDisplay()
{
    sizeofHeapSort = size;
    while (size > 1)
    {
        swap(this->arr[1], this->arr[size--]);
        modifyHeapTree(2);
    }
    size = sizeofHeapSort;
}

template <typename t>
void HeapTree <t> :: displayNormal()
{
    for (int i = 1; i <= size; i++)
    {
        cout<<this->arr[i] <<'\n';
    }
}

template <typename t>
void HeapTree <t> :: displaySortByNameAscendingly()
{
    if (!max) {
        Reverse_Max = true;
    }
    if (Reverse_Max) {
        max ^= 1;
    }
    modifyHeapTree(1);
    heapSortForDisplay();
    for (int i = 1; i <= size; i++)
    {
        cout<<this->arr[i] <<'\n';
    }
    if (Reverse_Max) {
        max ^= 1;
        Reverse_Max = false;
    }
    modifyHeapTree(1);
}

template <typename t>
void HeapTree <t> :: displaySortByNameDescendingly()
{
    if (max) {
        Reverse_Max = true;
    }
    if (Reverse_Max) {
        max ^= 1;
    }
    modifyHeapTree(1);
    heapSortForDisplay();
    for (int i = 1; i <= size; i++)
    {
        cout<<this->arr[i] <<'\n';
    }
    if (Reverse_Max) {
        max ^= 1;
        Reverse_Max = false;
    }
    modifyHeapTree(1);
}

template <typename t>
void HeapTree <t>::displaySortByPriceAscendingly()
{
    for (int i = 1; i <= size; i++)
    {
        this->arr[i].changeSortTechnique();
    }
    if (!max) {
        Reverse_Max = true;
    }
    if (Reverse_Max) {
        max ^= 1;
    }
    modifyHeapTree(1);
    heapSortForDisplay();
    for (int i = 1; i <= size; i++)
    {
        cout<<this->arr[i] <<'\n';
    }
    for (int i = 1; i <= size; i++)
    {
        this->arr[i].changeSortTechnique();
    }
    if (Reverse_Max) {
        max ^= 1;
        Reverse_Max = false;
    }
    modifyHeapTree(1);
}

template<typename t>
void HeapTree <t> :: displaySortByPriceDescendingly()
{
    for (int i = 1; i <= size; i++)
    {
        this->arr[i].changeSortTechnique();
    }
    if (max) {
        Reverse_Max = true;
    }
    if (Reverse_Max) {
        max ^= 1;
    }
    modifyHeapTree(1);
    heapSortForDisplay();
    for (int i = 1; i <= size; ++i)
    {
        cout<<this->arr[i] <<'\n';
    }
    for (int i = 1; i <= size; i++)
    {
        this->arr[i].changeSortTechnique();
    }
    if (Reverse_Max) {
        max ^= 1;
        Reverse_Max = false;
    }
    modifyHeapTree(1);
}

template <typename t>
HeapTree <t> :: ~HeapTree()
{
    delete[]this->arr;
}
