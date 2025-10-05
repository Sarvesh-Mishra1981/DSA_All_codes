/*
ceil is just opposite of the floor in  the ceil what we will do is that when we will traverse the let then we will just 
upadte the ans and same as that of the floor anf this is quite simple
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
right=NULL;}
};
int Ceil_InBST(Node* root,int x){
    int ans=0;
    while(root!=NULL){
        if(root->val==x) {ans=root->val; return ans;}
        else if(root->val<x){
            root=root->right;
        }
        else{
            ans=root->val;
            root=root->left;
        }
    }
    return ans;
}
Node* Insert(Node* root,int x){
    if(root==NULL) {
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
    cout<<Ceil_InBST(root,9)<<endl;
    return 0;
}
//time complexity of o(h)===>O(logn)