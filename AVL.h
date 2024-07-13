#pragma once

#include <iostream>
using namespace std;

template<class T>
struct Node {
    T key;
    Node<T>* left;
    Node<T>* right;
    int height;
};


template<class T>
class AVL {
public:
public:
    Node<T>* root;

private:    
    Node<T>* insert(Node<T>* node, T key);
    Node<T>* deleteNodeInternal(Node<T>* node, T key);
    Node<T>* minValueNode(Node<T>* node);
    int height(Node<T>* node);
    int max(int a, int b);
    int getBalance(Node<T>* node);
    Node<T>* rightRotate(Node<T>* y);
    Node<T>* leftRotate(Node<T>* x);
    void inorderTraversal(Node<T>* root);
    void preorderTraversal(Node<T>* root);
    void postorderTraversal(Node<T>* root);
    void calculateDiameter(Node<T>* node, int& diameter);
    Node<T>* findMin(Node<T>* node);
    Node<T>* findMax(Node<T>* node);
    Node<T>* findSuccessor(Node<T>* node, T key);
    Node<T>* findPredecessor(Node<T>* node, T key);


public:
    AVL();
    void insert(T key);
    void deleteNode(T key);
    Node<T>* search(Node<T>*, T);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    int height();
    int calculateDiameter();
    T findMin();
    T findMax();
    T findSuccessor(T key);
    T findPredecessor(T key);
    bool isEmpty();
};


template<class T>
AVL<T>::AVL() {
    root = nullptr;
}


template<class T>
int AVL<T>::height(Node<T>* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

template<class T>
int AVL<T>::max(int a, int b) {
    if (a > b)
    {
        return a;
    }
    else {
        return b;
    }
}

template<class T>
Node<T>* AVL<T>::rightRotate(Node<T>* y) {
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

template<class T>
Node<T>* AVL<T>::leftRotate(Node<T>* x) {
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

template<class T>
int AVL<T>::getBalance(Node<T>* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

template<class T>
Node<T>* AVL<T>::insert(Node<T>* node, T key) {
    if (node == nullptr) {
        Node<T>* newNode = new Node<T>();
        newNode->key = key;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->height = 1;
        return newNode;
    }

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template<class T>
Node<T>* AVL<T>::minValueNode(Node<T>* node) {
    Node<T>* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

template<class T>
Node<T>* AVL<T>::deleteNodeInternal(Node<T>* root, T key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNodeInternal(root->left, key);
    else if (key > root->key)
        root->right = deleteNodeInternal(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node<T>* temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else {
            Node<T>* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNodeInternal(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

template<class T>
Node<T>* AVL<T>::search(Node<T>* root, T key)
{
    
    if (root == nullptr || root->key == key) {
        return root;
    }

    
    if (root->key < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

template<class T>
void AVL<T>::inorderTraversal(Node<T>* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

template<class T>
void AVL<T>::preorderTraversal(Node<T>* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

template<class T>
void AVL<T>::postorderTraversal(Node<T>* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->key << " ";
    }
}

template<class T>
void AVL<T>::insert(T key) {
    root = insert(root, key);
}

template<class T>
void AVL<T>::deleteNode(T key) {
    root = deleteNodeInternal(root, key);
}

template<class T>
void AVL<T>::inorderTraversal() {
    inorderTraversal(root);
}

template<class T>
void AVL<T>::preorderTraversal() {
    preorderTraversal(root);
}

template<class T>
void AVL<T>::postorderTraversal() {
    postorderTraversal(root);
}

template<class T>
int AVL<T>::height() {
    return height(root);
}

template<class T>
void AVL<T>::calculateDiameter(Node<T>* node, int& diameter) {
    if (node == nullptr) return;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    diameter = max(diameter, leftHeight + rightHeight + 1);

    calculateDiameter(node->left, diameter);
    calculateDiameter(node->right, diameter);
}

template<class T>
int AVL<T>::calculateDiameter() {
    int diameter = 0;
    calculateDiameter(root, diameter);
    return diameter;
}

template<class T>
Node<T>* AVL<T>::findMin(Node<T>* node) {
    if (node == nullptr || node->left == nullptr)
        return node;
    return findMin(node->left);
}

template<class T>
T AVL<T>::findMin() {
    Node<T>* node = findMin(root);
    if (node == nullptr) return T();
    return node->key;
}

template<class T>
Node<T>* AVL<T>::findMax(Node<T>* node) {
    if (node == nullptr || node->right == nullptr)
        return node;
    return findMax(node->right);
}

template<class T>
T AVL<T>::findMax() {
    Node<T>* node = findMax(root);
    if (node == nullptr) return T();
    return node->key;
}

template<class T>
Node<T>* AVL<T>::findSuccessor(Node<T>* node, T key) {
    if (node == nullptr) return nullptr;

    Node<T>* successor = nullptr;
    while (node != nullptr) {
        if (key < node->key) {
            successor = node;
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return successor;
}

template<class T>
T AVL<T>::findSuccessor(T key) {
    Node<T>* node = findSuccessor(root, key);
    if (node == nullptr) return -1;
    return node->key;
}


template<class T>
Node<T>* AVL<T>::findPredecessor(Node<T>* node, T key) {
    if (node == nullptr) return nullptr;

    Node<T>* predecessor = nullptr;
    while (node != nullptr) {
        if (key > node->key) {
            predecessor = node;
            node = node->right;
        }
        else {
            node = node->left;
        }
    }
    return predecessor;
}

template<class T>
T AVL<T>::findPredecessor(T key) {
    Node<T>* node = findPredecessor(root, key);
    if (node == nullptr) return -1;
    return node->key;
}

template<class T>
bool AVL<T>::isEmpty() {
    return root == nullptr;
}