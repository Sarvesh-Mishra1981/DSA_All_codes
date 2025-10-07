/*
in this what we will do is that we will name the root as 0 and the left as the root-1 and the right as the root+1
so this will create the height wise division and those having aligned will lie in the same value;
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
class Node{
    public:
    Node* left,*right;
    int val;
    Node(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};
void vertical_sum_util(Node* root, unordered_map<int, int>& a, int l) {
    if (root == NULL) return;
    vertical_sum_util(root->left, a, l - 1);
    a[l] += root->val;
    vertical_sum_util(root->right, a, l + 1);
}

vector<int> vertical_sum(Node* root) {
    unordered_map<int, int> a;
    vertical_sum_util(root, a, 0);
    map<int, int> sorted(a.begin(), a.end());

    vector<int> result;
    for (auto& p : sorted) {
        result.push_back(p.second);
    }
    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> ans = vertical_sum(root);
    cout << "Vertical sums: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}