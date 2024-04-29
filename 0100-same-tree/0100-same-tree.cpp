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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if((p==NULL && q!=NULL) ||  (p!=NULL && q==NULL))  {
            return false;
        }
        bool left_t = isSameTree(p->left,q->left);
        bool right_t = isSameTree(p->right,q->right);
        bool check =(p->val  == q->val);
        if(left_t && right_t && check){
            return true;
        }
        else{
            return false;
        }

        
    }
};