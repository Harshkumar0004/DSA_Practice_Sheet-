#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool sametree(TreeNode* r1, TreeNode* r2) {
    if (!r1 && !r2) return true;
    if (!r1 || !r2) return false;
    if (r1->val != r2->val) return false;
    return sametree(r1->left, r2->left) && sametree(r1->right, r2->right);
}

int main() {
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << sametree(root1, root2) << endl; 
    return 0;
}
