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
    void solve(TreeNode* root, long long targetSum,int& count) {
        if(root==nullptr)
        {
        return;
        }
        
        
        targetSum=targetSum-root->val;
         
        if(targetSum==0)
       { count++;
       
       
        }
       
         solve(root->left,targetSum,count);
         solve(root->right,targetSum,count);
        

        
        
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        return 0;
        int count=0;
        solve(root,targetSum,count);
        count=count+pathSum(root->left,targetSum);
        count=count+pathSum(root->right,targetSum);
        return count;
    }
};