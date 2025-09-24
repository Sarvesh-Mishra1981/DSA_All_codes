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
//in the inorder Traversal we first go to the left node then the centre root then the the right node
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(){
    Node* head=new Node(10);
    head->left=new Node(20);
    head->right=new Node(30);
    inorder(head);
    return 0;

}