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
class Solution {
public:
long long sum=0;
long long best=INT_MIN;
long long MOD=1e9+7;
long long computeSum(TreeNode* root){
    if(!root)return 0;
    return root->val+computeSum(root->left)+computeSum(root->right);
}
    int maxProduct(TreeNode* root) {
     sum=computeSum(root);
     long long t=0;
     dfs(root,t);
     return best%MOD;
    }
    long long dfs(TreeNode* root,long long t){
        if(!root)return 0;
        t+=dfs(root->left,t)+
        dfs(root->right,t)+root->val;
        best=max(best,t*(sum-t));
        return t;
       

    }
};