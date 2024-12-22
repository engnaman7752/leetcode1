/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL)
    return NULL;
    if(root==p||root==q)
    {
        return root;
    }
TreeNode* lca;
        if(((p->val)-(root->val)<0)&&((q->val)-(root->val)<0))
        lca=lowestCommonAncestor(root->left,p,q);
        else if(((p->val)-(root->val)>0)&&((q->val)-(root->val)>0))
        lca=lowestCommonAncestor(root->right,p,q); 
        else
        lca=root;



        return lca;

    }
};