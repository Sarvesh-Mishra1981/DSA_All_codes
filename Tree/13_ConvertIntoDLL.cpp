#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

Node* prevNode = NULL;
Node* BTtoDLL(Node* root) {
    if (root == NULL) return root;

    Node* head = BTtoDLL(root->left);
    if (prevNode == NULL) {
        head = root;
    } else {
        root->left = prevNode;
        prevNode->right = root;
    }
    prevNode = root;
    BTtoDLL(root->right);
    return head;
}
void printDLL(Node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    Node* head = BTtoDLL(root);

    cout << "Doubly Linked List (Inorder): ";
    printDLL(head);

    return 0;
}
