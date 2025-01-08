
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";

        vector<string> ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp) {
                ans.push_back(to_string(temp->val));
                q.push(temp->left);
                q.push(temp->right);
            } else {
                ans.push_back("null");
            }
        }

    
        stringstream ss;
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i > 0) ss << ",";
            ss << ans[i];
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
        if (data == "null") return NULL;

        // Split the string into a vector<string>
        vector<string> nodes;
        stringstream ss(data);
        string node;
        while (getline(ss, node, ',')) {
            nodes.push_back(node);
        }

        if (nodes.empty() || nodes[0] == "null") return NULL;

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode* temp = q.front();
            q.pop();

            if (nodes[i] != "null") {
                temp->left = new TreeNode(stoi(nodes[i]));
                q.push(temp->left);
            }
            i++;

            if (i < nodes.size() && nodes[i] != "null") {
                temp->right = new TreeNode(stoi(nodes[i]));
                q.push(temp->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// string serializedData = ser.serialize(root);
// TreeNode* ans = deser.deserialize(serializedData);
