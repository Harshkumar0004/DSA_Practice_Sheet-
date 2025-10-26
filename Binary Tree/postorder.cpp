#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void postorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr)
        return;
    
    postorder(root->left, res);
    postorder(root->right, res);
    res.emplace_back(root->val);
}


vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    postorder(root, res);
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = postorderTraversal(root);
    for (int val : result)
        cout << val << " ";
    cout << endl;
    return 0;
}
