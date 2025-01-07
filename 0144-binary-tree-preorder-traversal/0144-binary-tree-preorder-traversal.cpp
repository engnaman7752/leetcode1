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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        while(root)
        {
            if(root->left==NULL)
           { ans.push_back(root->val);
            root=root->right;}
            else
            {
                TreeNode* current=root->left;
                while(current->right!=NULL&&current->right!=root)
                current=current->right;
                if(current->right==root)
                {current->right=NULL;
                root=root->right;}
                else
                {
                    ans.push_back(root->val);
                    current->right=root;
                    root=root->left;

                }


            }
        }
        return ans;
    }
};