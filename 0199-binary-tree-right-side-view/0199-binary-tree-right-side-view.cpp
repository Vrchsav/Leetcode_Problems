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
         if (!root) return {}; 
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>ans;
        int f;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            
            if(temp!=NULL){
                f=temp->val;
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            else{
                if(q.empty()){
                    break;
                }
                ans.push_back(f);
                q.push(NULL);


            }
            
            

        }
                ans.push_back(f);

                return ans;
        
    }
};