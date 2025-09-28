/*
so basically the diameter means that from one node the distance of left+ ditance of right+1 is called the diameter;
*/
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
int res=0;
int diameter(Node* root){// this function will find the height but on the way it will convert the res into diamter
if(root==NULL) return 0;
int lh=diameter(root->left);
int rh=diameter(root->right);
res=max(res,lh+rh+1);
return max(lh,rh)+1;
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
    head->right->right->left = new Node(14);
    head->right->right->right = new Node(15);
    diameter(head);
    cout<<res;
    return 0;
}
