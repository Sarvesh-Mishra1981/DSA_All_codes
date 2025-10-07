#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
the basic idea here is that we will use the hash map and there we will do the same thing as done in the 
hash we will find the diff
*/
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
bool Pair_withSum(Node* root,unordered_set<int>& m,int sum){
    if(root==NULL) return false;
    if(Pair_withSum(root->left,m,sum)){
        return true;
    }
    if(m.find(sum-root->val)!=m.end()){
        return true;
    }
    m.insert(root->val);
    return Pair_withSum(root->right,m,sum);
}
int main(){
Node *root = new Node(10);  
    root->left = new Node(8);  
    root->right = new Node(20);  
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);  
    root->right->right->left = new Node(25);
        
    int sum=33;
    unordered_set<int> s;    
    if(Pair_withSum(root,s,sum)) cout<<"Yes";
    else cout<<"No";
          
    return 0;  
}