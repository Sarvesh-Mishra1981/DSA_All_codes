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
//in the postorder Traversal we first go to the left node then the right node then the centre node
void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
int main(){
    Node* head=new Node(10);
    head->left=new Node(20);
    head->right=new Node(30);
    postorder(head);
    return 0;

}
// All of them have space complexity of O(h) and the time complexity of O(n)