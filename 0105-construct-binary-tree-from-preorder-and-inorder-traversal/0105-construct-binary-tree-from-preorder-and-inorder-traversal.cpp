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
    int position(vector<int>& inorder,int ele,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(ele==inorder[i])
            return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int start,int end,int n)
    {
        if(index>=n||start>end)
        return nullptr;
        int element=preorder[index++];
        TreeNode* temp=new TreeNode(element);
        int pos=position(inorder,element,n);
        temp->left=solve(preorder,inorder,index,start,pos-1,n);
        temp->right=solve(preorder,inorder,index,pos+1,end,n);
        return temp;


    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int index=0;
    TreeNode* temp=solve(preorder,inorder,index,0,n-1,n);
    return temp;


    }
};