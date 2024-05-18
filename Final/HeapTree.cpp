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
}

template <typename t>
void HeapTree <t> :: addItem (const t &item)
{
    if (size == 0)
    {
        this->arr[arrIndex] = item;
        !max? this->arr[arrIndex].descending(true) : this->arr[arrIndex].descending(false);
        size++;
    }
    else if (size > capacity)
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
        !max? this->arr[arrIndex].descending(true) : this->arr[arrIndex].descending(false);
        heapSort(size);
    }
    else
    {
        this->arr[++size] = item;
        !max? this->arr[arrIndex].descending(true) : this->arr[arrIndex].descending(false);
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
        while (i > 1 && this->arr[i/2] > data)
        {
            this->arr[i] = this->arr[i/2];
            i /= 2;
        }
    }
    else
    {
        while (i > 1 && this->arr[i/2] < data)
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
    for (int i = 1; i <= size; i++)
    {
        this->arr[i].descending(false);
    }
    modifyHeapTree(1);
    heapSortForDisplay();
    for (int i = 1; i <= size; i++)
    {
        cout<<this->arr[i] <<'\n';
    }
    modifyHeapTree(1);
}

template <typename t>
void HeapTree <t> :: displaySortByNameDescendingly()
{
    for (int i = 1; i <= size; i++)
    {
        this->arr[i].descending(true);
    }
    modifyHeapTree(1);
    heapSortForDisplay();
    for (int i = 1; i <= size; i++)
    {
        cout<<this->arr[i] <<'\n';
    }
    for (int i = 1; i <= size; i++)
    {
        this->arr[i].descending(false);
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
    for (int i = 1; i <= size; i++)
    {
        this->arr[i].descending(false);
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
    modifyHeapTree(1);
}

template<typename t>
void HeapTree <t> :: displaySortByPriceDescendingly()
{
    for (int i = 1; i <= size; i++)
    {
        this->arr[i].changeSortTechnique();
    }
    for (int i = 1; i <= size; i++)
    {
        this->arr[i].descending(true);
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
    for (int i = 1; i <= size; i++)
    {
        this->arr[i].descending(false);
    }
    modifyHeapTree(1);
}

template <typename t>
HeapTree <t> :: ~HeapTree()
{
    delete[]this->arr;
}
