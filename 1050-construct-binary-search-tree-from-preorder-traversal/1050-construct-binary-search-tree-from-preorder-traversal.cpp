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
    TreeNode* solve(vector<int>& preorder,int start,int end)
    {if (start >= end)  
        return nullptr;

    int value = preorder[start];
    TreeNode* root = new TreeNode(value);
    int i = start + 1; 
    while (i < end && preorder[i] < value) {
        i++;
    }
    root->left = solve(preorder, start + 1, i); 
    root->right = solve(preorder, i, end);  

    return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0)
        return nullptr;
        return solve(preorder,0,n);
    }
};