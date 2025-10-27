#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


int height(TreeNode* root) {
    if (root == nullptr)
        return 0; 
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + max(lh, rh);
}


int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout<< height(root) << endl;
    return 0;
}
