#include<iostream>
using namespace std;
#include<queue>
#include<stack>
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
/* 
The basic idea is that we will use the idea of the preorder traersal and then we will just push -1 if cell is empty.
*/
int empty=-1;
void serialize(vector<int>& a,Node* root){
    if(root==NULL){
        a.push_back(empty);
        return;
    }
    a.push_back(root->val);
    serialize(a,root->left);
    serialize(a,root->right);
}
int main() {
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    head->left->left->left = new Node(8);
    head->left->left->right = new Node(9);
    head->left->right->left = new Node(10);
    head->left->right->right = new Node(11);
    head->right->left->left = new Node(12);
    head->right->left->right = new Node(13);
    head->right->right->right = new Node(15);
    vector<int> a;
    serialize(a,head);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
