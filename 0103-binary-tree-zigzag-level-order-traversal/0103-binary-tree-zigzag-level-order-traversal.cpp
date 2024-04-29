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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>ans;
       if(root==NULL){
        return ans;
       }
        queue<TreeNode*> q;
        bool flag =true;
        q.push(root);

        
        while(!q.empty()){
            int n=q.size();
            vector<int>temp(n);
            for(int i=0;i<n;i++){
                TreeNode* front_N=q.front();
                q.pop();
                int index=flag ? i:n-i-1;
                temp[index]=front_N->val;

                if(front_N->left){
                    q.push(front_N->left);
                }
                if(front_N->right){
                    q.push(front_N->right);
                }
                
            }
            flag=!flag;
            ans.push_back(temp);
            temp.clear();
        }
return ans;
        
    }
};