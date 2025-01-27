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
    TreeNode* solve2(vector<TreeNode*>v,int start,int end)
    {
    if(start>end)
        return NULL;
        int mid=start+(end-start)/2;
        TreeNode* ans=v[mid];
    ans->left=solve2(v,start,mid-1);
    ans->right=solve2(v,mid+1,end);
    return ans;

    }
    void solve(TreeNode* root,vector<TreeNode*>&v)
    {
        if(root==NULL)
        return;
        solve(root->left,v);
        v.push_back(root);
        solve(root->right,v);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL)
        return NULL;
        vector<TreeNode*>v;
        solve(root,v);
        return solve2(v,0,v.size()-1);
        
    }
};