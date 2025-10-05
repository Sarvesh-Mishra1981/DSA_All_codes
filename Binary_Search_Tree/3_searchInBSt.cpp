/*
To search in bst we just use the simple same thing of comparing it with the root
*/
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
bool SearchBST(Node* root,int x){
    if(root==NULL) return false;
    if(root->val==x) return true;
    else if(root->val>x){
        return SearchBST(root->left,x);
    }
    else {
        return SearchBST(root->right,x);
    }
}
Node* Insert(Node* root,int x){
    if(root==NULL){
        return new Node(x);
    }
    else if(root->val>x){
        root->left=Insert(root->left,x);
    }
    else if(root->val<x){
        root->right=Insert(root->right,x);
    }
    return root;
}
int main(){
    Node* root = NULL;         
    vector<int> arr = {8, 3, 10, 1, 6, 14, 4, 7};  
    for(int x : arr) {
        root = Insert(root, x);
    }
    if(SearchBST(root,20)) {cout<<"Yes";}
    else cout<<"No";

    return 0;
}//time complexity is O(h)===> O(logn)