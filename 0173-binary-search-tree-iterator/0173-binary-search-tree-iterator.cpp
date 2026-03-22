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
class BSTIterator {
public:
vector<int>node;
int it=0;
    BSTIterator(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto nd=q.front();
            q.pop();
            node.push_back(nd->val);
            if(nd->left)q.push(nd->left);
            if(nd->right)q.push(nd->right);
        }
        sort(node.begin(),node.end());
    }
    
    int next() {
        it++;
        return node[it-1];
    }
    
    bool hasNext() {
        if(it>=node.size())return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */