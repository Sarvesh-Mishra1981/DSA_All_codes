#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int x) : key(x), left(NULL), right(NULL) {}
};
bool findPath(Node* root, vector<Node*>& path, int n) {
    if (root == NULL) return false;

    path.push_back(root);

    if (root->key == n) return true;

    if ((root->left && findPath(root->left, path, n)) ||
        (root->right && findPath(root->right, path, n)))
        return true;

    path.pop_back();
    return false;
}
Node* lca(Node* root, int n1, int n2) {
    vector<Node*> path1, path2;

    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return NULL;

    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++) {
        if (path1[i] != path2[i]) break;
    }
    return path1[i - 1];
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    int n1 = 40, n2 = 50;
    Node* ans = lca(root, n1, n2);

    if (ans != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is " << ans->key << endl;
    else
        cout << "Keys not present in tree." << endl;

    return 0;
}
// O(n) and space complexity is O(n)