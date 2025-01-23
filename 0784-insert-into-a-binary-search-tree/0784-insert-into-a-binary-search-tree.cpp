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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp=root;
        if(root==NULL)
        return new TreeNode (val);
        while(root)
        {
            if(root->val>val)
           { 
            if(root->left==NULL)
            {root->left=new TreeNode(val);
            break;}
            root=root->left;}
            else
            {
            if(root->right==NULL)
           { root->right=new TreeNode(val);
            break;}
            root=root->right;}
        }
       
        return temp;
        
    }
};