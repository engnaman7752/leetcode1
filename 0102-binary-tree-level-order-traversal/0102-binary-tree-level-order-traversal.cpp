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
void solve(vector<vector<int>>&ans,TreeNode *root)
{if(root==NULL)
return;
    queue<TreeNode*>q;
vector<int>row;
q.push(root);
q.push(NULL);
while(!q.empty())
 {TreeNode* temp=q.front();
 q.pop();
    if(temp==NULL)
{ans.push_back(row);
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

}
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        solve(ans,root);
        return ans;
        
    }
};