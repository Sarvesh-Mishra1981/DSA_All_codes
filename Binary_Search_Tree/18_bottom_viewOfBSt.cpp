/*
in this what we will do is that we will update the map till we get final element
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
void bottom_view(Node* root){
    queue<pair<Node*,int>> q;
    map<int,int> m;
    q.push({root,0});
    while(!q.empty()){
        Node* curr=q.front().first;
        int val=q.front().second;
        q.pop();
            m[val]=root->val;// we are continously upadting the value;
        if(curr->left!=NULL) {
            q.push({root->left,val-1});
        }
        if(curr->right!=NULL) {
            q.push({root->right,val+1});
        }
    }
    for(auto x:m){
        cout<<x.second<<" ";
    }
}
int main(){
Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    bottom_view(root);

    return 0;
}