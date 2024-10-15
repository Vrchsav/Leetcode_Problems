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
    int solve(TreeNode*root,int &ans){
        if(root==NULL){
            return 0;
        }
        int Left = max(0, solve(root->left, ans));  
        int Right = max(0, solve(root->right, ans)); 
        int currentMax = root->val + Left + Right;

        
        
        ans=max(ans,currentMax);
        return max(Left,Right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int t=solve(root,ans);
        return ans;
    }
};