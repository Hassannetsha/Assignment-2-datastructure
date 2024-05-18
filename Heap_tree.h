#ifndef ASSIGNMENT_2_DATASTRUCTURE_HEAP_TREE_H
#define ASSIGNMENT_2_DATASTRUCTURE_HEAP_TREE_H

#include "Item.h"
#include "Trees.h"
#include <cstdint>

template<typename t>
class Heap_tree : public Trees<t> {
private:
    int capacity, size, sizeofHeapSort, arrIndex;
    bool max, Reverse_Max;
public:
    explicit Heap_tree(const bool &max);

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

    void Heap_sort_for_display();
};

template<typename t>
void Heap_tree<t>::Heap_sort_for_display() {
    sizeofHeapSort = size;
    while (size > 1) {
        swap(this->arr[1], this->arr[size--]);
        Modify_Heap_tree(2);
    }
    size = sizeofHeapSort;
}

template<typename t>
void Heap_tree<t>::Display_sort_by_price_descending() {
    for (int i = 1; i <= size; ++i) {
        this->arr[i].change_sort_technique();
    }
    if (max) {
        Reverse_Max = true;
    }
    if (Reverse_Max) {
        max ^= 1;
    }
    Modify_Heap_tree(1);
    Heap_sort_for_display();
    for (int i = 1; i <= size; ++i) {
        cout << this->arr[i] << '\n';
    }
    for (int i = 1; i <= size; ++i) {
        this->arr[i].change_sort_technique();
    }
    if (Reverse_Max) {
        max ^= 1;
        Reverse_Max = false;
    }
    Modify_Heap_tree(1);
}

template<typename t>
void Heap_tree<t>::Display_sort_by_price_ascending() {
    for (int i = 1; i <= size; ++i) {
        this->arr[i].change_sort_technique();
    }
    if (!max) {
        Reverse_Max = true;
    }
    if (Reverse_Max) {
        max ^= 1;
    }
    Modify_Heap_tree(1);
    Heap_sort_for_display();
    for (int i = 1; i <= size; ++i) {
        cout << this->arr[i] << '\n';
    }
    for (int i = 1; i <= size; ++i) {
        this->arr[i].change_sort_technique();
    }
    if (Reverse_Max) {
        max ^= 1;
        Reverse_Max = false;
    }
    Modify_Heap_tree(1);
}

template<typename t>
void Heap_tree<t>::Display_sort_by_name_descending() {
    if (max) {
        Reverse_Max = true;
    }
    if (Reverse_Max) {
        max ^= 1;
    }
    Modify_Heap_tree(1);
    Heap_sort_for_display();
    for (int i = 1; i <= size; ++i) {
        cout << this->arr[i] << '\n';
    }
    if (Reverse_Max) {
        max ^= 1;
        Reverse_Max = false;
    }
    Modify_Heap_tree(1);
}

template<typename t>
void Heap_tree<t>::Display_sort_by_name_ascending() {
    if (!max) {
        Reverse_Max = true;
    }
    if (Reverse_Max) {
        max ^= 1;
    }
    Modify_Heap_tree(1);
    Heap_sort_for_display();
    for (int i = 1; i <= size; ++i) {
        cout << this->arr[i] << '\n';
    }
    if (Reverse_Max) {
        max ^= 1;
        Reverse_Max = false;
    }
    Modify_Heap_tree(1);
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
             this->arr[i] == Item("aaaaaaaaaaaaaaaaaaaa", " ", INT16_MIN)) && i != size) {
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
    if (!max) {
        while (i > 1 && data < this->arr[i / 2]) {
            this->arr[i] = this->arr[i / 2];
            i /= 2;
        }
    } else {
        while (i > 1 && data > this->arr[i / 2]) {
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
    if (index_to_delete > size || index_to_delete <= 0) {
        cout << "invalid index\n";
        exit(0);
    }
    int l = 2 * index_to_delete, r = 2 * index_to_delete + 1;
    if (index_to_delete > size) {
        return;
    }
    if (l <= size && r <= size && ((this->arr[l] < this->arr[r] && !max) || (this->arr[l] > this->arr[r] && max))) {
        swap(this->arr[index_to_delete], this->arr[l]);
        Delete_item(l);
    } else if (l <= size && r <= size &&
               ((this->arr[l] > this->arr[r] && !max) || (this->arr[l] < this->arr[r] && max))) {
        swap(this->arr[index_to_delete], this->arr[r]);
        Delete_item(r);
    } else {
        if (!max) { this->arr[index_to_delete] = Item("zzzzzzzzzzzzzzzzzzzz", " ", INT16_MAX); }
        else {
            this->arr[index_to_delete] = Item("aaaaaaaaaaaaaaaaaaaa", " ", INT16_MIN);
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
        this->arr[arrIndex] = item;
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
Heap_tree<t>::Heap_tree(const bool &max) {
    capacity = 10;
    size = 0;
    arrIndex = 1;
    this->arr = new t[capacity];
    this->max = max;
    this->Reverse_Max = false;
}

#endif
