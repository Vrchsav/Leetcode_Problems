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
    std::string serialize(TreeNode* root) {
        if (!root) return "";

        std::ostringstream oss;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                oss << node->val << ',';
                q.push(node->left);
                q.push(node->right);
            } else {
                oss << "#,";
            }
        }
        return oss.str();
    }

    TreeNode* deserialize(const std::string& data) {
        if (data.empty()) return nullptr;

        std::stringstream ss(data);
        std::string val;
        std::getline(ss, val, ',');
        TreeNode* root = new TreeNode(std::stoi(val));
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (std::getline(ss, val, ',')) {
                if (val != "#") {
                    TreeNode* left = new TreeNode(std::stoi(val));
                    node->left = left;
                    q.push(left);
                }
            }

            if (std::getline(ss, val, ',')) {
                if (val != "#") {
                    TreeNode* right = new TreeNode(std::stoi(val));
                    node->right = right;
                    q.push(right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));