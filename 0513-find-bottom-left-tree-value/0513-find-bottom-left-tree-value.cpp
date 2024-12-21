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
    void solve(TreeNode* root,map<int,int>&m,int lvl)
    {
        if(root==NULL)
        return;
        if(root->left==NULL&&root->right==NULL)
        {
            if(m.find(lvl)==m.end())
            m[lvl]=root->val;
            return;
        }
        if(root->left)
         solve(root->left,m,lvl+1);
        if(root->right)
         solve(root->right,m,lvl+1);

        

    }
public:
    int findBottomLeftValue(TreeNode* root) {
         int ans=0;
         if(root==NULL)
        return ans;
        map<int,int>m;
        int lvl=1;
        solve(root,m,lvl);
        int mini=0;
        for(auto i:m)
        {if(i.first>mini)
        ans=i.second;
        }
        return ans;
        

    
       
        
        
    }
};