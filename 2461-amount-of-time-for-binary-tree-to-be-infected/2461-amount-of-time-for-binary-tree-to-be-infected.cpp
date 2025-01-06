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
    void mapparent(TreeNode* root, map<TreeNode*,TreeNode*>& m,int start,TreeNode* & target)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
           TreeNode* temp=q.front();
           q.pop();
           if(temp->val==start)
           target=temp;
           if(temp->left)
           {m[temp->left]=temp;
           q.push(temp->left);}
           if(temp->right)
          { m[temp->right]=temp;
           q.push(temp->right);}


        }

    }
    void solve(int & ans,map<TreeNode*,bool>vis, map<TreeNode*,TreeNode*>m,queue<TreeNode*>q)
    {
        while(!q.empty())
        {bool flag= false;
        int size = q.size();
            
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
            ans++;
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        int ans=0;
        map<TreeNode*,TreeNode*>m;
        m[root]==NULL;
        TreeNode* target=NULL;
       mapparent(root,m,start,target);
       map<TreeNode*,bool>vis;
       vis[target]=true;
       queue<TreeNode*>q;
       q.push(target);
        solve(ans,vis,m,q);
        return ans;
        
    }
};