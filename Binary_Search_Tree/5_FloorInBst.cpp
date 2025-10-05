/*
The floor means that nyumber that is just smaller then the required number and So we can use the BST here as it 
very familiar to it as one end  the number is smaller and the other has the bigger number so in this condition 
what we will do is that when we will find the root smaller tehn the x then we will strore it and move right  


so the basic idea is that when we will move right we will store the value and return it
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
int FinTheFloor(Node* root,int x){
    int ans=-1;
    if(root==NULL) return ans;
    if(root->val==x) return root->val;
    else if(root->val>x){
        return FinTheFloor(root->left,x);
    }
    else {
        int floorRight = FinTheFloor(root->right, x);
        if (floorRight == -1) return root->val;
        else return floorRight;
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
    cout<<FinTheFloor(root,5)<<endl;
    return 0;
}