#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    Node* left,*right;
    Node(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};
Node* convert_bst(Node* root,int v){
    if(root==NULL){
        return new Node(v);
    }
    else if(root->val>v){
        root->left=convert_bst(root->left,v);
    }
    else if(root->val<v){
        root->right=convert_bst(root->right,v);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(){
 Node* root = NULL;         
    vector<int> arr = {8, 3, 10, 1, 6, 14, 4, 7};  
    for(int x : arr) {
        root = convert_bst(root, x);
    }
    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}