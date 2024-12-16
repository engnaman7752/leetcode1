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
    void hasPathSum(TreeNode* root, int targetSum,vector<int>&a,vector<vector<int>>&ans) {
        if(root==nullptr)
        {
        return;
        }
        
        a.push_back(root->val);
        targetSum=targetSum-root->val;
         
        if(targetSum==0&&(root->left==NULL&&root->right==NULL))
       { ans.push_back(a);
       
       
        }
       
         hasPathSum(root->left,targetSum,a,ans);
         hasPathSum(root->right,targetSum,a,ans);
         a.pop_back();

        
        
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>a;
        vector<vector<int>>ans;
        hasPathSum(root,targetSum,a,ans);
        return ans;
    }
};