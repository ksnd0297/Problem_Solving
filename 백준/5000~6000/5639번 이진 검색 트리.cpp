#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct NodeStruct
{
    int value;
    struct NodeStruct* leftChild;
    struct NodeStruct* rightChild;
}Node;

Node* root = NULL;

Node* BST_insert(Node* root, int value)
{
    if (root == NULL)
    {
        root = (Node*)malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        root->value = value;
        return root;
    }
    else
    {
        if (root->value > value)
            root->leftChild = BST_insert(root->leftChild, value);
        else
            root->rightChild = BST_insert(root->rightChild, value);
    }
    return root;
}

void BST_print(Node* root)
{
    if (root == NULL)
        return;

    BST_print(root->leftChild);
    BST_print(root->rightChild);
    cout << root->value << '\n';
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    while (1) {
        int num; cin >> num;
        if (cin.fail()) break;
        root = BST_insert(root, num);
    }

    BST_print(root);
    return 0;
}