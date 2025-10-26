#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void inorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr)
        return;
    
    inorder(root->left, res);
    res.emplace_back(root->val);
    inorder(root->right, res);
    
}


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = inorderTraversal(root);
    for (int val : result)
        cout << val << " ";
    cout << endl;
    return 0;
}
