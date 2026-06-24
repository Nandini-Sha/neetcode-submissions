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
        if (!root) return "NULL,";

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                s += "NULL,";
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "NULL,") return nullptr;

        vector<string> tokens;
        string cur;

        for (char c : data) {
            if (c == ',') {
                tokens.push_back(cur);
                cur.clear();
            } else {
                cur += c;
            }
        }

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < tokens.size()) {
            TreeNode* parent = q.front();
            q.pop();

            // Left child
            if (i < tokens.size() && tokens[i] != "NULL") {
                parent->left = new TreeNode(stoi(tokens[i]));
                q.push(parent->left);
            }
            i++;

            // Right child
            if (i < tokens.size() && tokens[i] != "NULL") {
                parent->right = new TreeNode(stoi(tokens[i]));
                q.push(parent->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));