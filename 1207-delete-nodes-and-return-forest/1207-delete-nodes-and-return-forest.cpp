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
    TreeNode* helper(TreeNode* root, set<int> stt,vector<TreeNode*>& ans){
        if(root==NULL){
            return NULL;
        }
        root->left=helper(root->left,stt,ans);
        root->right=helper(root->right,stt,ans);

        if(stt.find(root->val)!=stt.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            return NULL;
        }
        else{
            return root;
        }

    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>stt;
        for(int i=0;i<to_delete.size();i++){
            stt.insert(to_delete[i]);
        }
        vector<TreeNode*>ans;
        TreeNode* ro=helper(root,stt,ans);
        if(stt.find(root->val)==stt.end()){
            ans.push_back(root);
        }
        return ans;
    }
};