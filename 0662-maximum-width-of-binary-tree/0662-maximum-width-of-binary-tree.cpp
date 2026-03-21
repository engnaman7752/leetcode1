class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;

        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int s = q.size();
            long long first = q.front().second;
            long long m = 0, n = 1e18;

            for(int i = 0; i < s; i++){
                auto [nd, pos] = q.front();
                q.pop();

                pos = pos - first;   // normalization

                m = max(m, pos);
                n = min(n, pos);

                if(nd->left){
                    q.push({nd->left, pos*2 + 1});
                }
                if(nd->right){
                    q.push({nd->right, pos*2 + 2});
                }
            }

            ans = max(ans, (int)(m - n + 1));
        }

        return ans;
    }
};