/*
GROUP MEMBERS
1.GOODLUCK LUSELO
2.DANIEL NNKO
3.SAID MKILALU


This code defines a node struct representing a tree node with data and children. The operator function overloads the output stream operator
to print the tree structure. In the main function a simple tree is created and printed, showcasting the hierachical structure of the tree data.
*/



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void insertNode(Node*& root, int data) {
    if (root == nullptr) {
        root = createNode(data);
    } else if (data <= root->data) {
        insertNode(root->left, data);
    } else {
        insertNode(root->right, data);
    }
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 8);

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}