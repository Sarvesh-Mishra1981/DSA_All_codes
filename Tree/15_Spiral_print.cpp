#include<iostream>
using namespace std;
#include<queue>
#include<stack>
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
void PrintSpiral(Node* root){
    queue<Node *> q;
    stack<int> s;
    q.push(root);
    bool state=false;
    while(!q.empty()){
        int count=q.size();
    for(int i=0;i<count;i++){
         Node* head=q.front();
        q.pop();
        if(state){
            s.push(head->val);
        }
        else cout<<head->val<<" ";
        if(head->left!=NULL) q.push(head->left);
        if(root->right!=NULL) q.push(head->right);
        }
        if(state){
            while(!s.empty())
           { int x=s.top();
            cout<<x<<" ";
            s.pop();}
        }
        state=!state;
        cout<<endl;
    }
}
int main() {
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    head->left->left->left = new Node(8);
    head->left->left->right = new Node(9);
    head->left->right->left = new Node(10);
    head->left->right->right = new Node(11);
    head->right->left->left = new Node(12);
    head->right->left->right = new Node(13);
    head->right->right->left = new Node(14);
    head->right->right->right = new Node(15);
    PrintSpiral(head);
    return 0;
}
