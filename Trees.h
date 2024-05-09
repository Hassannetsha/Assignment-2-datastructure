#ifndef ASSIGNMENT_2_DATASTRUCTURE_TREES_H
#define ASSIGNMENT_2_DATASTRUCTURE_TREES_H

class Trees{
private:
    struct node {
        node *LChild;
        int data;
        int Height;
        node *RChild;
    };
    node *root;
public:
    Trees();
    virtual void Add_item() = 0;
    virtual void Delete_item() = 0;
    virtual void Display_normal() = 0;
    virtual void Display_sort_by_name_ascending() = 0;
    virtual void Display_sort_by_name_descending() = 0;
    virtual void Display_sort_by_price_ascending() = 0;
    virtual void Display_sort_by_price_descending() = 0;
};

Trees::Trees() {
    root = nullptr;
}

#endif