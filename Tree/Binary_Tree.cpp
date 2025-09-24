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
int main(){
    Node* head=new Node(10);
    head->left=new Node(20);
    head->right=new Node(30);
    return 0;
}