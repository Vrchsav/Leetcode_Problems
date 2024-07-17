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
private:
    void  ()
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
      map<  TreeNode*,TreeNode*>mp;
      mp[root]=NULL;
      queue<TreeNode*>q;
      q.push(root);
      while(!q.empty()){
        TreeNode*rr=q.front();
        q.pop();
        if(rr->left!=NULL){
            mp[rr->left]=rr;
            q.push(rr->left);
        }
        if(rr->right!=NULL){
            mp[rr->right]=rr;
            q.push(rr->right);

        }
      }


    }
};