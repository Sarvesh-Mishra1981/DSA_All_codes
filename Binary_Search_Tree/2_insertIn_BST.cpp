/*
In the insertion we just need to look on that root has greter value or smaller value and if the root becomes the null then we 
say that return New node(x)
*/
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    Node *left,*right;
    Node(int c){
        val=c;
        left=NULL;
        right=NULL;
    }
};
Node* insert(Node* root,int x){
    if(root==NULL) {
       return new Node(x);
    }
    else if(root->val>x){
        root->left=insert(root->left,x);
    }
     else if(root->val<x){
        root->right=insert(root->right,x);
    }

    return root;
}
void inorder(Node* root){
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(){
    Node* root = NULL;         
    vector<int> arr = {8, 3, 10, 1, 6, 14, 4, 7};  
    for(int x : arr) {
        root = insert(root, x);
    }
    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
// the time compxity is O(h)