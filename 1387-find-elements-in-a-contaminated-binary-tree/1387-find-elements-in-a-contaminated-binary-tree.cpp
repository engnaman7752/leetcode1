/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
    set<int>ans;
public:
 FindElements(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [temp, val] = q.front();
            q.pop();
            ans.insert(val);
            if (temp->left) {
                q.push({temp->left, 2 * val + 1});
            }
            if (temp->right) {
                q.push({temp->right, 2 * val + 2});
            }
        }
    }

    bool find(int target) {
        return ans.count(target);
    }
};
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */