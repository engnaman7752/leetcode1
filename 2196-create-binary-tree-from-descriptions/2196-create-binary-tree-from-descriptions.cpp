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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,bool>mp;
        map<int,TreeNode*>nodes;
        for(auto node:descriptions){
            if(nodes.find(node[0])==nodes.end()){
                TreeNode *temp=new TreeNode(node[0]);
                nodes[node[0]]=temp;
                mp[node[0]]=false;
            }
                if(node[2]==0){
                    if(mp.find(node[1])==mp.end())
                   { nodes[node[0]]->right=new TreeNode(node[1]);}
                   else{
                    nodes[node[0]]->right=nodes[node[1]];
                   }
                    mp[node[1]]=true;
                    nodes[node[1]]=nodes[node[0]]->right;
                }
                else{
                     if(mp.find(node[1])==mp.end())
                   { nodes[node[0]]->left=new TreeNode(node[1]);}
                   else{
                    nodes[node[0]]->left=nodes[node[1]];
                   }
                    mp[node[1]]=true;
                    nodes[node[1]]=nodes[node[0]]->left;
                }
        }
        for(auto it:mp){
            if(!it.second)return nodes[it.first];
        }
        return nullptr;
    }
};