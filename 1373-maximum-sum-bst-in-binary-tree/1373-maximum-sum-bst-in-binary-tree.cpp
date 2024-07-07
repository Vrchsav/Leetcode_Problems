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

class info{
    public:
        int maxi;
        int mini;
        bool isBst;
        int sum;
};
class Solution {



public:

    info solve(TreeNode *root,int &ans){
        if(root==NULL){
            return {INT_MIN,INT_MAX,true,0};
        }

        info left =solve(root->left,ans);
        info right =solve(root->right,ans);

        info currNode;
        currNode.maxi=max(root->val,right.maxi);
        currNode.mini=min(root->val,left.mini);
        currNode.sum =root->val+right.sum+left.sum;

        if(left.isBst && right.isBst && (root->val > left.maxi && root->val < right.mini)){
            currNode.isBst=true;
        }
        else{
            currNode.isBst=false;
            return currNode;

        }
        if(currNode.isBst){
            ans=max(ans,currNode.sum);
        }
        return currNode;


    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        info t=solve(root,ans);
        return ans;
    }
};