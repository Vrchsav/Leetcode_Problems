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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q; // Use unsigned long long to avoid overflow
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            int n = q.size();
            unsigned long long left = q.front().second; // Store the left-most index for the current level
            unsigned long long right = q.back().second; // Store the right-most index for the current level
            ans = max(ans, static_cast<int>(right - left + 1)); // Calculate width of the current level

            for (int i = 0; i < n; ++i) {
                auto temp = q.front();
                q.pop();
                unsigned long long idx = temp.second - left; // Make the indices relative to avoid overflow
                if (temp.first->left) {
                    q.push({temp.first->left, 2 * idx + 1});
                }
                if (temp.first->right) {
                    q.push({temp.first->right, 2 * idx + 2});
                }
            }
        }
        return ans;
    }
};
