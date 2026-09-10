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
int cnt=0;
    int averageOfSubtree(TreeNode* root) {
         solve(root);
        return cnt;
    }
    pair<int,int>solve(TreeNode* root){
        if(root==nullptr)return {0,0};
        int sum=root->val;
        int num=1;
        auto [leftSum,leftn]=solve(root->left);
        auto [rightSum,rightn]=solve(root->right);
        sum+=leftSum+rightSum;
        num+=leftn+rightn;
        if((sum/num)==root->val)cnt++;
        return {sum,num};
    }
};