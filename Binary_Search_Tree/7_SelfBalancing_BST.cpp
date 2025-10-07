/*
So what is the basic idea is that in BST the height if the log(n) so all the opreation such as search and delete will be O(logn)
so we nned to convert a BST in balanced treee



The Tradition way ------- If you have array/vector nad want to convert in into Balanced BST then---:
1. Sort the array
2. go to the centre and make the new root and then call for the left and the right in the smae fashion
3.resulting the tree in balanced fromat
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
Node* conevrtVector_Balanced_Bst(vector<int>& a,int low,int high){
    if(low>high) return NULL;
    int mid=(low+high)/2;
    Node* root=new Node(a[mid]);
    root->left=conevrtVector_Balanced_Bst(a,low,mid-1);
    root->right=conevrtVector_Balanced_Bst(a,mid+1,high);
    return root;
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(){
    vector<int> arr = {7, 2, 9, 1, 5, 8, 3};
    //sort the array---- 
    sort(arr.begin(),arr.end());
    Node* root=conevrtVector_Balanced_Bst(arr,0,arr.size()-1);
    inorder(root);
}