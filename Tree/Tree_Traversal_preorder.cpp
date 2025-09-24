#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *left,*right;
    Node(int x){
        val=x;
        left=NULL;
        right=NULL; 
    }
};
//in the preorder Traversal we first go to the root node then we go to the left and then right
void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node* head=new Node(10);
    head->left=new Node(20);
    head->right=new Node(30);
    preorder(head);
    return 0;

}