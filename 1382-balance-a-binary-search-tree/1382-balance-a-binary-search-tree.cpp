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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>v;
        dfs(root,v);
        int n=v.size();
        return bst(v,0,n-1);
    }
    void dfs(TreeNode* root,vector<TreeNode*>&v){
        if(!root)return;
        dfs(root->left,v);
         v.push_back(root);
        dfs(root->right,v);
    }
    TreeNode* bst(vector<TreeNode*>&v,int start,int end){
        if(start>end)return nullptr;
        int mid=start+(end-start)/2;
        TreeNode* root=v[mid];
        root->left=bst(v,start,mid-1);
        root->right=bst(v,mid+1,end);
        return root;

    }
};