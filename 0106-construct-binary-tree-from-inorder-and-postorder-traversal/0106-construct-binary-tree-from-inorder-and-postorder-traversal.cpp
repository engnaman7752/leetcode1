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
    int position(vector<int>& inorder,int ele)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(ele==inorder[i])
            return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int& index,int start,int end,map<int,int>m)
    {if(index<0||start>end)
    return nullptr;
        int element=postorder[index--];
        TreeNode* temp=new TreeNode(element);
        //int pos=m[element];
        int pos=position(inorder,element);
        temp->right=solve(inorder,postorder,index,pos+1,end,m);
        temp->left=solve(inorder,postorder,index,start,pos-1,m);
        return temp;

        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int index=n-1;
        map<int,int>m;
        // for(int i=0;i<n;i++)
        // {
        //     m[inorder[i]]=i;
        // }
        TreeNode* temp=solve(inorder,postorder,index,0,n-1,m);
        return temp;
    }
};