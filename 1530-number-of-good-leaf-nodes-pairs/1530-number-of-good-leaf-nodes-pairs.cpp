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
    int solve(TreeNode* root, int distance, int length, int &ans) {
        if (root == NULL) {
            return 0;
        }
        
        if (root->left == NULL && root->right == NULL) {
            return length;
        }
        
        int left = solve(root->left, distance, length + 1, ans);
        int right = solve(root->right, distance, length + 1, ans);
        
        if (left != 0 && right != 0 && left + right - 2 * length <= distance) {
            ans++;
        }
        
        return max(left, right);
    }
    
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        solve(root, distance, 0, ans);
        return ans;
    }
};