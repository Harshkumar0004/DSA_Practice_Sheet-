#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValid(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValid(root->left, minVal, root->val) &&
           isValid(root->right, root->val, maxVal);
}

bool checkBST(TreeNode* root) {
    return isValid(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(8);  

    cout << "Tree 1 is BST: " << checkBST(root1) << endl;
    cout << "Tree 2 is BST: " << checkBST(root2) << endl;

    return 0;
}
