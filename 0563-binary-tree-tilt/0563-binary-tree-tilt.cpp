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
int sum(TreeNode* root)
{int summ=0;
    if(root==nullptr)
    return 0;
    summ=summ+root->val;
    summ=summ+sum(root->left);
    summ=summ+sum(root->right);
    return summ;
}
    int findTilt(TreeNode* root) {
        if(root==NULL)
        return 0;
        int ans=0;
        ans=ans+abs(sum(root->left)-sum(root->right));
         ans=ans+findTilt(root->left);
       ans=ans+findTilt(root->right);

        return ans;
    }
};