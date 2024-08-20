class Solution {
    void solve(vector<int>& candidates, int target,int sum,int index,vector<vector<int>>&ans,vector<int>&ds ){
        if(sum==target ){
            ans.push_back(ds);
            return;
        }
        if(index>=candidates.size() || sum>target){
            return;
        }
        
        ds.push_back(candidates[index]);
        solve(candidates,target,sum+candidates[index],index,ans,ds);
        ds.pop_back();
        solve(candidates,target,sum,index+1,ans,ds);


    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
       vector<int>ds;
        solve(candidates,target,0,0,ans,ds);
        return ans;
 
    }
};