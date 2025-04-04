class Solution {
private:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        return left && right ? root : left ? left : right;
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr; 
        if(!root->left&&!root->right)
        return root;

        vector<set<TreeNode*>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            set<TreeNode*> s;
            int len = q.size();

            for (int i = 0; i < len; i++) {
                TreeNode* x = q.front();
                q.pop();
                if (x->left) { q.push(x->left); s.insert(x->left); }
                if (x->right) { q.push(x->right); s.insert(x->right); }
            }
            if (!s.empty()) ans.push_back(s);
        }

        if (ans.empty()) return nullptr;  

        auto it = ans.back().begin();
        TreeNode* res = *it;
        for (++it; it != ans.back().end(); ++it) {
            res = lca(root, res, *it);
        }
        return res;
    }
};
