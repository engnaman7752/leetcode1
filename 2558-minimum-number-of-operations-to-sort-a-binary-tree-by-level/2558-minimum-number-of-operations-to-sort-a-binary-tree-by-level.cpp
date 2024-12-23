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
     int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({arr[i], i});
        }
        sort(vec.begin(), vec.end());
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i] || vec[i].second == i) {
                continue;
            }
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = vec[j].second;
                cycle_size++;
            }
            if (cycle_size > 1) {
                ans += (cycle_size - 1);
            }
        }
        return ans;}
void solve(TreeNode *root,int& ans)
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
{{ans=ans+minSwaps(row);

row.clear();}
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
    int minimumOperations(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};