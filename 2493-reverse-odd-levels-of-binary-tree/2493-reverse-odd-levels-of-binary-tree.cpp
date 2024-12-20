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
    private: 
    void solve(int l,TreeNode* left,TreeNode* right)
    {if(left==NULL||right==NULL)
    return ;
    if(l%2==1)
       swap(left->val,right->val);
        
        solve(l+1,left->left,right->right);
        solve(l+1,left->right,right->left);}
    
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        int l=1;
        solve(l,root->left,root->right);
        return root;
    }
};