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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        if(root==NULL)
        return ans;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty())
        {
            pair<TreeNode*,pair<int,int>> temp=q.front();
            q.pop();
            TreeNode* front=temp.first;
            int lvl=temp.second.second;
            int hd=temp.second.first;
            nodes [hd][lvl].insert(front->val);
            if(front->left)
            q.push(make_pair(front->left,make_pair(hd-1,lvl+1)));
            if(front->right)
            q.push(make_pair(front->right,make_pair(hd+1,lvl+1)));


        }
        for(auto i:nodes)
        {vector<int>col;
            for(auto j:i.second)
            {
                col.insert(col.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};