/*
The idea of the vertical traversal is that we will move downwards and same as that of sum but we will do here the same as bfs traversal
*/
#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
// for the vertical traversal usig the idea of the queue;
void traversal(Node* root){
    queue<pair<Node*,int>> q;
    map<int,vector<int>> m;
    q.push({root,0});
    while(!q.empty()){
        Node* curr=q.front().first;
        int val=q.front().second;
        q.pop();
        m[val].push_back(curr->val);
        if(curr->left!=NULL) {
            q.push({root->left,val-1});
        }
        if(curr->right!=NULL) {
            q.push({root->right,val+1});
        }
    }
    for(auto x:m){
        vector<int> a=x.second;
        for(int y:a){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}
int main(){
Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    traversal(root);

    return 0;
}