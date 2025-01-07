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
    void flatten(TreeNode* root) {
        TreeNode* temp=root;
         while(root)
        {
            if(root->left==NULL)
           { 
            root=root->right;}
            else
            {
                TreeNode* current=root->left;
                while(current->right!=NULL&&current->right!=root)
                current=current->right;
                if(current->right==root)
                {
                root=root->right;}
                else
                {
                    
                    current->right=root->right;
                    root->right=NULL;
                    root=root->left;

                }


            }
        }
        root=temp;
        while(root)
        {
            if(root->left)
           { root->right=root->left;
            root->left=NULL;}
            root=root->right;
        }
    }
};