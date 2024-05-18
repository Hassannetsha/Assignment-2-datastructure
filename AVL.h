#ifndef ASSIGNMENT_2_DATASTRUCTURE_AVL_TREE_H
#define ASSIGNMENT_2_DATASTRUCTURE_AVL_TREE_H

#include <iostream>
#include "Item.h"
#include "Trees.h"

using namespace std;

template<typename t>
class AVLTree : public Trees<t> {
private:
    struct AVLNode {
        t data;
        AVLNode* left;
        AVLNode* right;
        int height;

        explicit AVLNode(const t& item)
                : data(item), left(nullptr), right(nullptr), height(1) {}
    };

    AVLNode* nameRoot;
    AVLNode* priceRoot;
    int size, capacity;
public:
    AVLTree() : nameRoot(nullptr), priceRoot(nullptr), size(0), capacity(10){
        this->arr = new t[capacity];
    }

    ~AVLTree() {
        clear(nameRoot);
        clear(priceRoot);
    }

    void Add_item(const t& item) override {
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

        nameRoot = insert(nameRoot, item);
        t item2 = item;
        item2.change_sort_technique();
        priceRoot = insert(priceRoot, item2);
        size++;
    }

    void Delete_item(const int& index_to_delete) override {
        if (index_to_delete < 1 || index_to_delete > size)
            return;
        AVLNode* nodeToBeDeleted = findNode(nameRoot, this->arr[index_to_delete-1]);
        nameRoot = removeNode(nodeToBeDeleted, this->arr[index_to_delete-1]);
        nodeToBeDeleted = findNode(priceRoot, this->arr[index_to_delete-1]);
        priceRoot = removeNode(nodeToBeDeleted, this->arr[index_to_delete-1]);

        for (int i = index_to_delete-1; i < size-1; i++)
        {
            this->arr[i] = this->arr[i+1];
        }
        size--;
        cout<<"\nItem deleted successfully!\n";
    }

    void Display_normal() override {
        for (int i = 0; i < size; i++)
        {
            cout<<this->arr[i] <<'\n';
        }
    }

    void Display_sort_by_name_ascending() override {
        inorder(nameRoot);
        cout << endl;
    }

    void Display_sort_by_name_descending() override {
        reverse_inorder(nameRoot);
        cout << endl;
    }

    void Display_sort_by_price_ascending() override {
        inorder(priceRoot);
        cout << endl;
    }

    void Display_sort_by_price_descending() override {
        reverse_inorder(priceRoot);
        cout << endl;
    }

private:
    AVLNode* insert(AVLNode* node, const t& value) {
        if (node == nullptr) {
            return new AVLNode(value);
        }
        if (node->data > value) {
            node->left = insert(node->left, value);
        } else if (node->data < value) {
            node->right = insert(node->right, value);
        } else {
            return node;
        }

        node->height = calculateHeight(node);

        int balance = getBalance(node);
        if (balance > 1 && node->left->data > value)
            return rotateRight(node);

        if (balance < -1 && node->right->data < value)
            return rotateLeft(node);

        if (balance > 1 && node->left->data < value) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && node->right->data > value) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode* findNode(AVLNode* node, const t& value) {
        if (node->data == value) {
            return node;
        }
        if (node->data > value) {
            return findNode(node->left, value);
        } else {
            return findNode(node->right, value);
        }
    }

    AVLNode* removeNode(AVLNode* node, const t& value) {
        if (node == nullptr) {
            return node;
        }

        if (node->data > value) {
            node->left = removeNode(node->left, value);
        } else if (node->data < value) {
            node->right = removeNode(node->right, value);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                AVLNode* temp = node->left ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    node =temp;
                }
                delete temp;
            }
            else
            {
                AVLNode* temp = minValueNode(node->right);

                node->data = temp->data;

                node->right = removeNode(node->right, temp->data);
            }
        }

        if (node == nullptr) {
            return node;
        }

        node->height = calculateHeight(node);

        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) {
            return rotateRight(node);
        }

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0) {
            return rotateLeft(node);
        }

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    int calculateHeight(AVLNode* node) {
        if (node == nullptr)
            return 0;
        int left_height = (node->left != nullptr) ? node->left->height : 0;
        int right_height = (node->right != nullptr) ? node->right->height : 0;
        return 1 + max(left_height, right_height);
    }

    int getBalance(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return calculateHeight(node->left) - calculateHeight(node->right);
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = calculateHeight(y);
        x->height = calculateHeight(x);

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = calculateHeight(x);
        y->height = calculateHeight(y);

        return y;
    }

    void clear(AVLNode* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void inorder(AVLNode* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data <<'\n';
            inorder(root->right);
        }
    }

    void reverse_inorder(AVLNode* root) {
        if (root != nullptr) {
            reverse_inorder(root->right);
            cout << root->data <<'\n';
            reverse_inorder(root->left);
        }
    }
};

#endif // ASSIGNMENT_2_DATASTRUCTURE_AVL_TREE_H
