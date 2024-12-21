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
     void solve(TreeNode* root,int lvl,TreeNode*prev,int &ans)
    {
        if(root==NULL)
        return;
        if(root->left==NULL&&root->right==NULL&&prev->left==root)
        {
           ans=ans+root->val;
            return;
        }
        if(root->left)
         solve(root->left,lvl+1,root,ans);
        if(root->right)
         solve(root->right,lvl+1,root,ans);
        
        
         

        

    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
         int ans=0;
         if(root==NULL||(root->left==NULL&&root->right==NULL))
        return ans;
      
        TreeNode* prev=root;
        int lvl=1;
        solve(root->left,lvl,prev,ans);
        solve(root->right,lvl,prev,ans);
       
        return ans;
    }
};