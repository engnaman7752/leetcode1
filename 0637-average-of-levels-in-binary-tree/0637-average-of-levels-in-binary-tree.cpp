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
    void solve(vector<double>&ans,TreeNode *root)
{if(root==NULL)
return;
    queue<TreeNode*>q;
vector<int>row;
q.push(root);


while(!q.empty())
{double sum=0;
int n=q.size();
for(int i=0;i<n;i++)
   { TreeNode* temp=q.front();
      q.pop();
      sum=sum+temp->val;
    if(temp->left)
   { q.push(temp->left);}
    if(temp->right)
   { q.push(temp->right);}}
   ans.push_back(sum/n);
}

 }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        solve(ans,root);
        return ans;
        
    }
};