/*
in this waht we will do is that we will make the stack and there we will do is that we will insert all the left
elements teher and then same count theory and then we will also add the right element there as 
this theory so like the ancestor root will have the smaller value in left as well as right

here the time complexity is O(h) and the spae complexity id O(h)
//thid is even inorder based approch but in iterative form
*/
#include<iostream>
#include<vector>
#include<stack>
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
Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    return root;
}
int KthElement(Node* root,int k){
    stack<Node*> s;
    while(s.empty() || root!=NULL){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
        root=s.top();
        s.pop();
        if(--k==0){
            cout<<root->val;
        }
        root=root->right;
    }
    return -1;
}
int main(){
Node* root = NULL;
    vector<int> keys = {5, 3, 7, 2, 4, 6, 8};

    for (int x : keys)
        root = insert(root, x);

    int k = 3;
    int ans = KthElement(root, k);

    if (ans != -1)
        cout << k << "-th smallest element is " << ans << endl;
    else
        cout << "Less than " << k << " elements in the tree." << endl;

    return 0;
}