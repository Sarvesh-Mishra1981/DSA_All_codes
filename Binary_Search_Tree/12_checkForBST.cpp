/*
So the basic approch is that if in naive approch will be 
we will look for the max element in the left and the max in the right and if we get the root in between it then it is fine

The good approch is that you will set the max and the min value and if the root is in between it then it will be good and 
if it fails the it will be false ;;; it is O(n) approch

the other approch is that if bst is correct then there is fact that its inorder traversal will be sorted--O(n)
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Node{
public:
    int val;
    Node *left,*right;
    Node(int v){
    val=v;
    left=NULL;
    right=NULL;
}
};
bool isBST(Node* root,int max,int min){
if(root==NULL) return true;
return(root->val<max && root->val>min && isBST(root->left,root->val,min) && isBST(root->right,max,root->val));
}

int main(){
Node *root = new Node(4);  
    root->left = new Node(2);  
    root->right = new Node(5);  
    root->left->left = new Node(1);  
    root->left->right = new Node(3);  
      
    if(isBST(root,INT_MAX,INT_MIN))  
        cout<<"Is BST";  
    else
        cout<<"Not a BST";  
          
    return 0;  
	
}
