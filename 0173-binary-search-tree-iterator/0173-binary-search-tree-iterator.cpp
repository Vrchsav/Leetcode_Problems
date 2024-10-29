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
class BSTIterator {
public:
    stack<TreeNode*>stt;
    BSTIterator(TreeNode* root) {
        while(root!=NULL){
            stt.push(root);
            root =root->left;
        }
    }
    
    
    int next() {
        auto temp=stt.top();
        int ans=temp->val;
        
        stt.pop();
        temp=temp->right; 
        while(temp!=NULL){
            stt.push(temp);
            temp=temp->left;
        }
        return ans;
        


    }
    
    bool hasNext() {
        return !stt.empty();
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */