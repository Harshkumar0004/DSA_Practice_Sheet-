#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> levelOrderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr)
        return res;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        res.push_back(node->val);

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }

    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = levelOrderTraversal(root);
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
