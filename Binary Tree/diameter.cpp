#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int ans = 0;

int height(TreeNode* r) {
    if (!r) return 0;
    int lh = height(r->left);
    int rh = height(r->right);
    ans = max(ans, lh + rh);
    return 1 + max(lh, rh);
}

int diameter(TreeNode* root) {
    ans = 0;
    height(root);
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << diameter(root) << endl;
    return 0;
}
