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
    bool isBalanced(TreeNode* root) {
        if(dfs(root)==-1)return false;
        else return true;
    }
    int dfs(TreeNode* root){
        if(root==nullptr)return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        if(l==-1)return -1;
        if(r==-1)return -1;
        if(abs(l-r)>1)return -1;
        return 1+max(l,r);


    }
};