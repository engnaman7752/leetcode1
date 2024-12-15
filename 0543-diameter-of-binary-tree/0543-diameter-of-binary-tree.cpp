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
    pair<int,int>naman(TreeNode* root)
    {
        if(root==NULL)
        { pair<int,int>p;
        p.first=0;
        p.second=0;
        return p;}
        pair<int,int>left=naman(root->left);
        pair<int,int>right=naman(root->right);
       int op1=left.first;
       int op2=right.first;
       int op3=left.second+right.second;
        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
      
        return ans;

      
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return naman(root).first;
       
    }
};