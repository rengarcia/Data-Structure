#pragma once
#include <iostream>

using namespace std;

/*---------  Tree Structure  ------------*/
typedef class Node {
public:
    int number;
    Node* left, * right;
}*ABB;
/*----------------------------------------*/

ABB createNode(int x) {
    ABB newNode = new(Node);
    newNode->number = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void insert(ABB& tree, int x) {
    if (tree == NULL) {
        tree = createNode(x);
    }
    else if (x < tree->number)
        insert(tree->left, x);
    else if (x > tree->number)
        insert(tree->right, x);
}