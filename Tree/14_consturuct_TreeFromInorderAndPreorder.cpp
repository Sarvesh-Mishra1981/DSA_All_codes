#include <iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
int preindex=0;
Node* ConvertIntoTree(vector<int>& a,vector<int>& b,int st,int end){
    if(st>end) return NULL;
    int inindex=0;
    Node* root=new Node(b[preindex++]);
    for(int i=0;i<a.size();i++){
        if(a[i]==root->val){
            inindex=i;
            break;
        }
    }
   root->left= ConvertIntoTree(a,b,st,inindex-1);
    root->right=ConvertIntoTree(a,b,inindex+1,end);//this is because we wnat that centre right should be right na dthe left one should be left;
    return root;
}
void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
   vector<int> a{40,20,50,10,30,80,70,90};
    vector<int> b{10,20,40,50,30,70,80,90};
    Node* root=ConvertIntoTree(a,b,0,a.size()-1);
    preorder(root);
    return 0;
}
