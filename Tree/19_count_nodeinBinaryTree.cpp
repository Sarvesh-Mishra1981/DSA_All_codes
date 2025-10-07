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
int countNodes(Node* root){
    /*
    the basic idea is very clear and same as the size_of_binry tree but there is one test case where we can calculate in very speed 
    when the tree is complete then we can do the 2(n) is the answer 
    so what we will do is that we will find the lh and rh and if they are same then we will return 2(n) else 1+lh+rh;
    */
   int lh=0,rh=0;
   Node* curr=root;
   while(curr!=NULL){
    curr=curr->left;
    lh++;
   }
   curr=root;
   while(curr!=NULL){
    curr=curr->right;
    rh++;
   }
   if(lh==rh){
    return pow(2,lh)-1;
   }
   return 1+lh+rh;
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
    cout<<countNodes(head);
    return 0;
}
