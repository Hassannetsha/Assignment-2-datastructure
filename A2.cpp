#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include "Item.h"
#include "Item.cpp"
#include "Trees.h"
#include "BinarySearchTree.cpp"
#include "HeapTree.cpp"
#include "AVLTree.cpp"

using namespace std;
using namespace this_thread;
using namespace chrono;


void readItems (ifstream &file, Trees <Item>* tree)
{
    string line;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            string name, category, priceStr;
            name = line;
            if (getline(file, category) && getline(file, priceStr))
            {
                double price = stod(priceStr);
                tree->addItem(Item(name, category, price));
            }
            getline(file, line);
        }
        file.close();
        cout<<"\nItems added successfully\n";
    }
    else
    {
        cerr<<"\nUnable to open file!\n";
    }
}

int main()
{
    Trees <Item>* tree;
    int choice;
    bool check = true;
    cout<<"Welcome to the Supermarket Item Registration Program :)\n";
    while (check)
    {
        sleep_for(milliseconds (55));
        cout<<"\n--------------------------------------------------------------------\n"
            <<"\nWould you like to enter the items in a:\n"
            <<"1- Binary Search Tree\n"
            <<"2- Heap\n"
            <<"3- AVL Tree\n"
            <<"Please enter the number of your choice:";
        cin>>choice;
        cin.ignore();
        switch (choice)
        {
            case 1:
                tree = new BinarySearchTree <Item>;
                check = false;
                break;

            case 2:
                cout<<"\nWould you like the Heap to be a 1-Min Heap 2-Max Heap?";
                cin>>choice;
                cin.ignore();
                if (choice == 1)
                    tree = new HeapTree <Item> (false);
                else if (choice == 2)
                    tree = new HeapTree <Item> (true);
                check = false;
                break;

            case 3:
                tree = new AVLTree <Item>;
                check = false;
                break;

            default:
                cerr<<"\nPlease enter a valid number!\n";
        }
    }
    check = true;
    while (check)
    {
        sleep_for(milliseconds (55));
        cout<<"\n--------------------------------------------------------------------\n"
            <<"\nWould you like to:\n"
            <<"1- Add (an) item(s)\n"
            <<"2- Remove an item\n"
            <<"3- Display items normally\n"
            <<"4- Display items sorted by their name ascendingly\n"
            <<"5- Display items sorted by their name descendingly\n"
            <<"6- Display items sorted by their price ascendingly\n"
            <<"7- Display items sorted by their price descendingly\n"
            <<"0- Exit\n"
            <<"Please enter the number of your choice:";
        cin>>choice;
        cin.ignore();
        switch (choice)
        {
            case 1:
                cout<<"\nWould you like to add the item(s) 1-Manually 2-From a file?";
                cin>>choice;
                cin.ignore();
                if (choice == 1)
                {
                    string name, category;
                    double price;
                    cout<<"\nPlease enter the name of the item:";
                    getline(cin, name);
                    cout<<"Please enter the category of the item:";
                    getline(cin, category);
                    cout<<"Please enter the price of the item:";
                    cin>>price;
                    cin.ignore();
                    tree->addItem(Item(name, category, price));
                    cout<<"\nItem added successfully!\n";
                }
                else if (choice == 2)
                {
                    string fileName;
                    cout<<"\nPlease enter the file name:";
                    getline(cin, fileName);
                    fileName += ".txt";
                    ifstream file(fileName);
                    readItems(file, tree);
                }
                break;

            case 2:
                tree->displayToDelete();
                int num;
                cout<<"\nPlease enter the number of the item you want to remove:";
                cin>>num;
                cin.ignore();
                tree->deleteItem(num);
                break;

            case 3:
                cout<<"\nItems registered:\n";
                tree->displayNormal();
                break;

            case 4:
                cout<<"\nItems registered:\n";
                tree->displaySortByNameAscendingly();
                break;

            case 5:
                cout<<"\nItems registered:\n";
                tree->displaySortByNameDescendingly();
                break;

            case 6:
                cout<<"\nItems registered:\n";
                tree->displaySortByPriceAscendingly();
                break;

            case 7:
                cout<<"\nItems registered:\n";
                tree->displaySortByPriceDescendingly();
                break;

            case 0:
                cout<<"\nThank you for using the Supermarket Item Registration Program :)\n";
                check = false;
                break;

            default:
                cerr<<"\nPlease enter a valid number!\n";
        }
    }
}
