#include "Heap_tree.h"
using namespace std;
int main(){
    Trees<Item>* test = new Heap_tree<Item>(false);
    test->Add_item(Item("cantaloupe","fruit",20));
    test->Add_item(Item("doulab","feature",20));
    test->Add_item(Item("banana","fruit",75));
    test->Add_item(Item("Elephant","animal",75));
    test->Add_item(Item("fish","animal",75));
    test->Add_item(Item("apple","fruit",10));
    test->Add_item(Item("giraffe","fruit",10));
    test->Delete_item(1);
/*
 * fruit apple 10
feature doulab 20
fruit banana 75
animal Elephant 75
animal fish 75
fruit cantaloupe 20
fruit giraffe 10
 */
    test->Display_sort_by_name_descending();
//    cout<<"\n-------------------\n\n";
//    test->Display_normal();
    delete test;
}