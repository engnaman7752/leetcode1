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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL)
        return 0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int ans=INT_MIN;
        int sum=0;
        int l=0;
        map<int,int>m;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            
             if(temp==NULL)
             {
                m[l]=sum;
                sum=0;
                l++;
                if(!q.empty())
                q.push(NULL);

             }
             else
             {sum=sum+temp->val;
             if(temp->left)
             q.push(temp->left);
             if(temp->right)
             q.push(temp->right);}

        }
        int maxi=INT_MIN;
        for(auto i:m)
        {if(i.second>maxi)
       { ans=i.first+1;
        maxi=i.second;}
        

        }  
        return ans;  }
};