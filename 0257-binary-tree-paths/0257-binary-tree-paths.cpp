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
    void path(TreeNode* root, string &a,vector<string>&ans) {
        if(root==nullptr)
        {
        return;
        }
      if (!a.empty()) {
            a += "->";  
        }  
       a += to_string(root->val);
       

        if(root->left==NULL&&root->right==NULL)
       { 
        ans.push_back(a);
        

       }
       
         path(root->left,a,ans);
         path(root->right,a,ans);
         int toRemove = to_string(root->val).length();
if (!a.empty() && a.length() > toRemove) {
    a.erase(a.end() - toRemove, a.end());  
    if (a.length() >= 2) {
        a.erase(a.end() - 2, a.end());  
    }
}


        
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
         string a;
        vector<string>ans;
        path(root,a,ans);
        return ans;
    }
};