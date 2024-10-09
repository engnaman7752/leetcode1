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
    void solve(vector<vector<int>>&ans,TreeNode *root)
{if(root==NULL)
return;
    queue<TreeNode*>q;
    stack<vector<int>>st;
vector<int>row;
q.push(root);
q.push(NULL);
while(!q.empty())
 {TreeNode* temp=q.front();
 q.pop();
    if(temp==NULL)
{st.push(row);
row.clear();
if(!q.empty())
q.push(NULL);}

else
   {  row.push_back(temp->val);

    if(temp->left)
   { q.push(temp->left);}
    if(temp->right)
   { q.push(temp->right);}}


 }
 while(!st.empty())
 {ans.push_back(st.top());
 st.pop();}

}
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         vector<vector<int>>ans;
        solve(ans,root);
        return ans;
    }
};