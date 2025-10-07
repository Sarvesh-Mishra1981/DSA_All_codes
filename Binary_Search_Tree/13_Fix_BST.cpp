/*
the idea is that we will make the 3 nodeand then we will travese inorder and then we will find the 
node and in the main function we will reverse it;
*/
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    Node*left,*right;
    Node(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
Node *prevv=NULL,*first=NULL,*second=NULL;
void Fix_BST(Node* root){
    if(root==NULL) return;
    Fix_BST(root->left);
    if(prevv!=NULL && root->val<prevv->val){
        if(first==NULL){
            first=prevv;
        }
        second=root;//fisrt we need to select the big oe then we need to seleect the small one so if(root<prev) then root is small hence ham second ko root banate hai
    }
    prevv=root;
    Fix_BST(root->right);
}
int main(){
Node *root = new Node(18);  
    root->left = new Node(60);  
    root->right = new Node(70);  
    root->left->left = new Node(4);  
    root->right->left = new Node(8);
    root->right->right = new Node(80);  
    
    inorder(root); 
    cout<<endl;
    Fix_BST(root);
    int temp=first->val;
    first->val=second->val;
    second->val=temp;
    inorder(root);
          
    return 0;  
}