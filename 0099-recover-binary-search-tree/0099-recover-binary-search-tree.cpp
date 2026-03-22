class Solution {
public: 
    vector<TreeNode*> node;
    void recoverTree(TreeNode* root) {
        solve(root);
        int n = node.size();
        TreeNode *first = NULL, *second = NULL;
        for (int i = 0; i < n - 1; i++) {
            if (node[i]->val > node[i + 1]->val) {
                if (!first) first = node[i];
                second = node[i + 1];
            }
        }
        swap(first->val, second->val);
    }

    void solve(TreeNode* root) {
        if (root == NULL) return;
        solve(root->left);
        node.push_back(root);
        solve(root->right);
    }
};