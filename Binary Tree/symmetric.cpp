#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool ismirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    return (left->val == right->val) &&
           ismirror(left->left, right->right) &&
           ismirror(left->right, right->left);
}

bool issymmetric(TreeNode* root) {
    if (!root) return true;
    return ismirror(root->left, root->right);
}

int main() {

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);

    cout << "Tree 1 is symmetric: " << issymmetric(root1) << endl;
    cout << "Tree 2 is symmetric: " << issymmetric(root2) << endl; 

    return 0;
}
