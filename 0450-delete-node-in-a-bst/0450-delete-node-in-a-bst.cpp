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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            if(root->left==NULL && root->right==NULL ){
                delete(root);
                return NULL;
            }
            if(root->left==NULL && root->right!=NULL ){
                TreeNode* temp=root->right;
                delete(root);
                return temp;
            }
            if(root->left!=NULL && root->right==NULL ){
                TreeNode* temp=root->left;
                delete(root);
                return temp;
            }
            else{
                TreeNode*temp=root->left;
                while(temp->right){
                    temp=temp->right;
                }
                swap(temp->val,root->val);
                root->left=deleteNode(root->left,key);
                return root;

            }

        }
        if(root->val >key){
            root->left=deleteNode(root->left,key);
        }
        else{
            root->right=deleteNode(root->right,key);
        }
        return root;
        
    }
};