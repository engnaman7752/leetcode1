class Solution {
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd) {
        if (preStart > preEnd) 
            return nullptr;

      
        TreeNode* root = new TreeNode(preorder[preStart]);

        
        if (preStart == preEnd) 
            return root;

        int leftChild = preorder[preStart + 1];
        int leftEnd = postStart;
        while (postorder[leftEnd] != leftChild) 
            leftEnd++;

        
        int leftSize = leftEnd - postStart + 1;

        root->left = solve(preorder, postorder, preStart + 1, preStart + leftSize, postStart, leftEnd);
        root->right = solve(preorder, postorder, preStart + leftSize + 1, preEnd, leftEnd + 1, postEnd - 1);

        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return solve(preorder, postorder, 0, n - 1, 0, n - 1);
    }
};
