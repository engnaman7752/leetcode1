class Solution {
public:
    int sum = 0;
    vector<int> solve(TreeNode* root) {
        if (!root) return {1, 0, INT_MAX, INT_MIN};
        auto l = solve(root->left);
        auto r = solve(root->right);
        if (l[0] && r[0] && root->val > l[3] && root->val < r[2]) {
            int currSum = root->val + l[1] + r[1];
            sum = max(sum, currSum);
            int mn = min(root->val, l[2]);
            int mx = max(root->val, r[3]);
            return {1, currSum, mn, mx};
        }
        return {0, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return sum;
    }
};