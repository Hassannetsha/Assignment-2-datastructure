#include <iostream>
#include "Trees.h"
#include "Item.h"

using namespace std;

template <typename t>
AVLTree <t> :: AVLTree()
{
    nameRoot = priceRoot = nullptr;
    size = 0;
    capacity = 10;
    this->arr = new t[capacity];
}

template <typename t>
typename AVLTree <t> :: node* AVLTree <t> :: insert (node* root, const t& item)
{
    if (root == nullptr)
    {
        return new node(item);
    }
    if (root->data >= item)
    {
        root->LChild = insert(root->LChild, item);
    }
    else if (root->data < item)
    {
        root->RChild = insert(root->RChild, item);
    }
    else
    {
        return root;
    }

    root->height = calculateHeight(root);
    int balance = getBalance(root);

    if (balance > 1 && root->LChild->data > item)
    {
        return rotateRight(root);
    }
    if (balance < -1 && root->RChild->data < item)
    {
        return rotateLeft(root);
    }
    if (balance > 1 && root->LChild->data < item)
    {
        root->LChild = rotateLeft(root->LChild);
        return rotateRight(root);
    }
    if (balance < -1 && root->RChild->data > item)
    {
        root->RChild = rotateRight(root->RChild);
        return rotateLeft(root);
    }
    return root;
}

template <typename t>
void AVLTree <t> :: addItem (const t &item)
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

    nameRoot = insert(nameRoot, item);
    t item2 = item;
    item2.changeSortTechnique();
    priceRoot = insert(priceRoot, item2);
    size++;
}

template <typename t>
void AVLTree <t> :: displayToDelete()
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
typename AVLTree <t> :: node* AVLTree <t> :: findNode (node* node, const t& item)
{
    if (node->data == item)
    {
        return node;
    }
    if (node->data > item)
    {
        return findNode(node->LChild, item);
    }
    else
    {
        return findNode(node->RChild, item);
    }
}

template <typename t>
typename AVLTree <t> :: node* AVLTree <t> :: removeNode (node* node)
{
    if (node->LChild == nullptr || node->RChild == nullptr)
    {
        AVLTree<t>::node* temp = node->LChild ? node->LChild : node->RChild;
        if (temp == nullptr)
        {
            node = nullptr;
        }
        else
        {
            node = temp;
        }
        delete temp;
    }
    else
    {
        AVLTree<t>::node* temp = minValueNode(node->RChild);
        node->data = temp->data;
        node->RChild = removeNode(node->RChild);
    }

    if (node == nullptr)
    {
        return node;
    }
    node->height = calculateHeight(node);
    int balance = getBalance(node);
    if (balance > 1 && getBalance(node->LChild) >= 0)
    {
        return rotateRight(node);
    }
    if (balance > 1 && getBalance(node->LChild) < 0)
    {
        node->LChild = rotateLeft(node->LChild);
        return rotateRight(node);
    }
    if (balance < -1 && getBalance(node->RChild) <= 0)
    {
        return rotateLeft(node);
    }
    if (balance < -1 && getBalance(node->RChild) > 0)
    {
        node->RChild = rotateRight(node->RChild);
        return rotateLeft(node);
    }
    return node;
}

template <typename t>
void AVLTree <t> :: deleteItem (const int &index)
{
    if (index < 1 || index > size)
    {
        cerr<<"\nInvalid number!\n";
        return;
    }

    node* nodeToBeDeleted = findNode(nameRoot, this->arr[index-1]);
    nameRoot = removeNode(nodeToBeDeleted);

    nodeToBeDeleted = findNode(priceRoot, this->arr[index-1]);
    priceRoot = removeNode(nodeToBeDeleted);

    for (int i = index-1; i < size-1; i++)
    {
        this->arr[i] = this->arr[i+1];
    }
    size--;
    cout<<"\nItem deleted successfully!\n";
}

template <typename t>
typename AVLTree <t> :: node* AVLTree <t> :: minValueNode (node* node)
{
    AVLTree<t>::node* current = node;
    while (current->LChild != nullptr)
    {
        current = current->LChild;
    }
    return current;
}

template <typename t>
int AVLTree <t> :: calculateHeight (node* node)
{
    if (node == nullptr)
        return 0;
    int leftHeight = (node->LChild != nullptr)? node->LChild->height : 0;
    int rightHeight = (node->RChild != nullptr)? node->RChild->height : 0;
    return 1 + max(leftHeight, rightHeight);
}

template <typename t>
int AVLTree <t> :: getBalance (node* node)
{
    if (node == nullptr)
        return 0;
    return calculateHeight(node->LChild) - calculateHeight(node->RChild);
}

template <typename t>
typename AVLTree <t> :: node* AVLTree <t> :: rotateRight (node* node)
{
    AVLTree<t>::node* x = node->LChild;
    AVLTree<t>::node* T2 = x->RChild;
    x->RChild = node;
    node->LChild = T2;
    node->height = calculateHeight(node);
    x->height = calculateHeight(x);
    return x;
}

template <typename t>
typename AVLTree <t> :: node* AVLTree <t> :: rotateLeft (node* node)
{
    AVLTree<t>::node* x = node->RChild;
    AVLTree<t>::node* T2 = x->LChild;
    x->LChild = node;
    node->RChild = T2;
    node->height = calculateHeight(node);
    x->height = calculateHeight(x);
    return x;
}

template <typename t>
void AVLTree <t> :: inorder (node* root)
{
    if (root != nullptr)
    {
        inorder(root->LChild);
        cout<<root->data <<'\n';
        inorder(root->RChild);
    }
}

template <typename t>
void AVLTree <t> :: reverseInorder (node* root)
{
    if (root != nullptr)
    {
        reverseInorder(root->RChild);
        cout<<root->data <<'\n';
        reverseInorder(root->LChild);
    }
}

template <typename t>
void AVLTree <t> :: displayNormal()
{
    for (int i = 0; i < size; i++)
    {
        cout<<this->arr[i] <<'\n';
    }
}

template <typename t>
void AVLTree <t> :: displaySortByNameAscendingly()
{
    inorder(nameRoot);
}

template <typename t>
void AVLTree <t> :: displaySortByNameDescendingly()
{
    reverseInorder(nameRoot);
}

template <typename t>
void AVLTree <t> ::displaySortByPriceAscendingly()
{
    inorder(priceRoot);
}

template <typename t>
void AVLTree <t> ::displaySortByPriceDescendingly()
{
    reverseInorder(priceRoot);
}

template <typename t>
void AVLTree <t> :: clear (node* node)
{
    if (node != nullptr)
    {
        clear(node->LChild);
        clear(node->RChild);
        delete node;
    }
}

template <typename t>
AVLTree <t> :: ~AVLTree()
{
    clear(nameRoot);
    clear(priceRoot);
}
