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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==nullptr)return nullptr;
        unordered_set<TreeNode*>s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            unordered_set<TreeNode*>st;
            for(int i=0;i<k;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left){
                    st.insert(temp->left);
                    q.push(temp->left);
                }
                if(temp->right){
                    st.insert(temp->right);
                    q.push(temp->right);
                }
            }
        if(!st.empty())
        s=st;
        }
        if(s.empty())return root;
        TreeNode* ans=*s.begin();
        for(auto it:s){
            ans=lca(root,ans,it);
        }
        return ans;
    }
TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
   if (!root || root == p || root == q) return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
       if(left&&right)return root;
       else{
        if(left)return left;
        if(right)return right;
       }
       return nullptr;
}
};