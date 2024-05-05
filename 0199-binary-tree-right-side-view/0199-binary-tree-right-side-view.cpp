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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        map<int,int> top_n;
        queue<pair<TreeNode*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<TreeNode*,int>temp=q.front();
            q.pop();
            TreeNode* front_n=temp.first;
            int level=temp.second;
           

           
                top_n[level]=front_n->val;
            

            if(front_n->left){
                q.push(make_pair(front_n->left,level+1));
            }
            if(front_n->right){
                q.push(make_pair(front_n->right,level+1));
            }
            }
        
        for (auto i : top_n) {
            ans.push_back(i.second);
        }
        return ans;
    }
};