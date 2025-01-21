/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
   void map_parent(TreeNode* root,map<TreeNode*,TreeNode*>&m)
    {
        queue<TreeNode*>q;
        m[root]=NULL;
        q.push(root);
        while(!q.empty())
        { int k=q.size();
           for(int i=0;i<k;i++)
            {TreeNode* temp=q.front();
             q.pop();
                if(temp->left)
                {m[temp->left]=temp;
                q.push(temp->left);}
               if(temp->right)
                {m[temp->right]=temp;
                q.push(temp->right);}
            }
        }
    }
queue<TreeNode*>solve(TreeNode* target, int k, map<TreeNode*,TreeNode*> & m,map<TreeNode*,bool>& vis)
{      queue<TreeNode*>q;
        q.push(target);
        int count=0;
       while(!q.empty())
        {bool flag= false;
        int size = q.size();
            if(count==k)
            break;
            for (int i = 0; i < size; i++) 
            {TreeNode* temp=q.front();
            q.pop();
            if(temp->left!=NULL&&(!vis[temp->left]))
            {
                vis[temp->left]=true;
                q.push(temp->left);
                flag=true;

            }
            if(temp->right!=NULL&&(!vis[temp->right]))
            {
                vis[temp->right]=true;
                q.push(temp->right);
                flag=true;

            }
            if(m[temp]!=NULL&&(!vis[m[temp]]))
            {
                vis[m[temp]]=true;
                q.push(m[temp]);
                flag=true;

            }
            }
            if(flag)
           { count++;
            }
        }
        return q;
}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        map<TreeNode*,TreeNode*>m;
        map_parent(root,m);
        map<TreeNode*,bool>vis;
        vis[target]=true;
        queue<TreeNode*>q=solve(target,k,m,vis);
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};