#include <iostream>
using namespace std;

// Make struct for the node in BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to store the nodes after traversal
void storeNodes(Node *root, int arr[], int &i) {
    if(root != NULL) {
        storeNodes(root->left, arr, i);
        arr[i++] = root->data;
        storeNodes(root->right, arr, i);
    }
}

// Function to insert a node into BST
Node *insertNode(Node *root, int value) {
    if(root == NULL)
        return new Node(value);

    if(value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

//Function to do binary tree sort
void binarytreeSort(int arr[], int size) {
    struct Node *root = NULL;

    root = insertNode(root, arr[0]);
    for(int i = 1; i < size; i++) {
        root = insertNode(root, arr[i]);
    }

    int i = 0;
    storeNodes(root, arr, i);
}

int main() {
    int arr[10] = {182, 309, 404, 568, 686, 398, 330, 25, 132, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    binarytreeSort(arr, size);

    cout << "Binary tree sorted: [";
    for(int i = 0; i < size; i++) {
        // When reached the latest element, don't print the ","
        (i == size-1)
            ?cout << arr[i] << "]"
            :cout << arr[i] << ", ";
    }

    return 0;
}
