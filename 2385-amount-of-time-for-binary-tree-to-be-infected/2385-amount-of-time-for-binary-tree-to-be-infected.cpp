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
    TreeNode*parentmapping(TreeNode* root, int start,map<TreeNode*,TreeNode*>&map_p){
        queue<TreeNode*>q;
        TreeNode*res=NULL;
        q.push(root);
        map_p[root]=NULL;
        while(!q.empty()){
            TreeNode*front=q.front();
            q.pop();
            if(front->val==start){
                res=front;
            }
            if(front->left){
                map_p[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                map_p[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }

    int infected(TreeNode*targetNode, map<TreeNode*,TreeNode*>&map_p){
        map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        visited[targetNode]=true;
        int ans=0;

        q.push(targetNode);
        while(!q.empty()){
            bool flag=false;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*front=q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    flag=true;
                    visited[front->left]=1;
                    q.push(front->left);
                }
                if(front->right && !visited[front->right]){
                    flag=true;
                    visited[front->right]=1;
                    q.push(front->right);
                }
                if( map_p[front]&& !visited[map_p[front]]){
                    flag=true;
                    visited[map_p[front]]=1;
                    q.push(map_p[front]);
                }
            }
            if(flag){
                ans++;
                flag=false;
            }

        }
        return ans;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>map_p;
        TreeNode*targetNode=parentmapping(root,start,map_p);
        int ans=infected(targetNode,map_p);
        return ans;
    }
};