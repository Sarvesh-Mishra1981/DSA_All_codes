/*
The idea of the kth smaleest element is that we can resolve this using the priority_queue
but in this we use the idea of the inorder traversal this is O(n) solution with O(h) space 
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
// so this is te baisc implemenatation 
void printk(Node* root,int count,int k){
    if(root!=NULL){
        printk(root->left,count,k);
        count++;
        if(count==k){
            cout<<root->val;
            return;
        }
        printk(root->right,count,k);
    }
}
int main(){
    	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int k=3;
	int count=0;
	cout<<"Kth Smallest: ";
	printk(root,count,k);
	
	return 0;
}