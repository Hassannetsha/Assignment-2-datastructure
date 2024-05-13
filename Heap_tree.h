#ifndef ASSIGNMENT_2_DATASTRUCTURE_HEAP_TREE_H
#define ASSIGNMENT_2_DATASTRUCTURE_HEAP_TREE_H

#include "Item.h"
#include "Trees.h"
#include <bits/stdc++.h>

template<typename t>
class Heap_tree : public Trees<t> {
private:
    int capacity;
    int size;
    int index;
    bool MAX;
    int ctn_delete;
public:
    explicit Heap_tree(const bool &MAX);

    ~Heap_tree();

    void Heap_sort(const int &node_to_sort);

    void Add_item(const t &item) override;

    bool check();

    void Delete_item(const int &index_to_delete) override;

    void Display_normal() override;

    void Modify_Heap_tree(const int &start);

    void Display_sort_by_name_ascending();

    void Display_sort_by_name_descending();

    void Display_sort_by_price_ascending();

    void Display_sort_by_price_descending();

};

template<typename t>
void Heap_tree<t>::Display_sort_by_price_descending() {
    t *arr2 = new t[size + 1];
    arr2[0] = Item();
    for (int i = 1; i <= size; ++i) {
        arr2[i] = this->arr[i];
    }
    for (int i = 1; i <= size; ++i) {
        arr2[i].change_sort_technique();
    }
    for (int i = 1; i <= size; ++i) {
        arr2[i].descending();
    }
    sort(arr2 + 1, arr2 + size + 1);
    for (int i = 1; i <= size; ++i) {
        cout << arr2[i] << '\n';
    }
    delete[] arr2;
}

template<typename t>
void Heap_tree<t>::Display_sort_by_price_ascending() {
    t *arr2 = new t[size + 1];
    arr2[0] = Item();
    for (int i = 1; i <= size; ++i) {
        arr2[i] = this->arr[i];
    }
    for (int i = 1; i <= size; ++i) {
        arr2[i].change_sort_technique();
    }
    sort(arr2 + 1, arr2 + size + 1);
    for (int i = 1; i <= size; ++i) {
        cout << arr2[i] << '\n';
    }/*
 *
    fruit giraffe 10
    animal Elephant 75
    animal fish 75
    fruit cantaloupe 20
    feature doulab 20
    fruit apple 10
    fruit banana 75
 */
    delete[] arr2;
}

template<typename t>
void Heap_tree<t>::Display_sort_by_name_descending() {
    t *arr2 = new t[size + 1];
    arr2[0] = Item();
    for (int i = 1; i <= size; ++i) {
        arr2[i] = this->arr[i];
    }
    for (int i = 1; i <= size; ++i) {
        arr2[i].descending();
    }
    sort(arr2 + 1, arr2 + size + 1);
    for (int i = 1; i <= size; ++i) {
        cout << arr2[i] << '\n';
    }
    delete[] arr2;
}

template<typename t>
void Heap_tree<t>::Display_sort_by_name_ascending() {
    t *arr2 = new t[size + 1];
    arr2[0] = Item();
    for (int i = 1; i <= size; ++i) {
        arr2[i] = this->arr[i];
    }
    sort(arr2 + 1, arr2 + size + 1);
    for (int i = 1; i <= size; ++i) {
        cout << arr2[i] << '\n';
    }
    delete[] arr2;
}

template<typename t>
void Heap_tree<t>::Modify_Heap_tree(const int &start) {
    for (int i = start; i <= size; ++i) {
        Heap_sort(i);
    }
}

template<typename t>
bool Heap_tree<t>::check() {
    for (int i = 1; i < size; ++i) {
        if ((this->arr[i] ==
             Item("zzzzzzzzzzzzzzzzzzzz", " ", INT16_MAX) ||
             this->arr[i] == Item("zzzzzzzzzzzzzzzzzzzz", " ", INT16_MIN)) && i != size) {
            return false;
        }
    }
    return true;
}

template<typename t>
Heap_tree<t>::~Heap_tree() {
    delete[] this->arr;
}

template<typename t>
void Heap_tree<t>::Heap_sort(const int &node_to_sort) {
    int i = node_to_sort;
    t data = this->arr[i];
    this->arr[i] = data;
    if (!MAX) {
        while (i > 1 && this->arr[i / 2] > data) {
            this->arr[i] = this->arr[i / 2];
            i /= 2;
        }
    } else {
        while (i > 1 && this->arr[i / 2] < data) {
            this->arr[i] = this->arr[i / 2];
            i /= 2;
        }
    }
    this->arr[i] = data;
}

template<typename t>
void Heap_tree<t>::Display_normal() {
    for (int i = 1; i <= size; ++i) {
        cout << this->arr[i] << "\n";
    }
}

template<typename t>
void Heap_tree<t>::Delete_item(const int &index_to_delete) {
    if (index_to_delete > size) {
        cout << "invalid index\n";
    }
    int l = 2 * index_to_delete, r = 2 * index_to_delete + 1;
    if (index_to_delete > size) {
        return;
    }
    if (l <= size && r <= size && ((this->arr[l] < this->arr[r] && !MAX) || (this->arr[l] > this->arr[r] && MAX))) {
        swap(this->arr[index_to_delete], this->arr[l]);
        Delete_item(l);
    } else if (l <= size && r <= size &&
               ((this->arr[l] > this->arr[r] && !MAX) || (this->arr[l] < this->arr[r] && MAX))) {
        swap(this->arr[index_to_delete], this->arr[r]);
        Delete_item(r);
    } else {
        ctn_delete++;
        if (!MAX) { this->arr[index_to_delete] = Item("zzzzzzzzzzzzzzzzzzzz", " ", INT16_MAX); }
        else {
            this->arr[index_to_delete] = Item("zzzzzzzzzzzzzzzzzzzz", " ", INT16_MIN);
        }
        if (!check()) {
            swap(this->arr[index_to_delete], this->arr[size]);
            Modify_Heap_tree(index_to_delete);
        }
        size--;
    }
}

template<typename t>
void Heap_tree<t>::Add_item(const t &item) {
    if (size == 0) {
        this->arr[index] = item;
        size++;
    } else if (size > capacity) {
        capacity *= 2;
        t *arr2 = new t[capacity];
        for (int i = 1; i < size; ++i) {
            arr2[i] = this->arr[i];
        }
        delete this->arr;
        this->arr = arr2;
        this->arr[++size] = item;
        Heap_sort(size);
    } else {
        this->arr[++size] = item;
        Heap_sort(size);
    }
}

template<typename t>
Heap_tree<t>::Heap_tree(const bool &MAX) {
    ctn_delete = 0;
    capacity = 10;
    size = 0;
    index = 1;
    this->arr = new t[capacity];
    this->MAX = MAX;
}

#endif
