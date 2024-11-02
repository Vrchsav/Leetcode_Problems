class Solution {
public:
       
    bool dfs( vector<int>&dfsvisited,vector<int>&visited,int src,  vector<vector<int>>&arr ){      
        visited[src]=1;
        dfsvisited[src]=1;

        for(auto a:arr[src]){
            if(visited[a]==0){
                if(dfs(dfsvisited,visited,a,arr)==true){
                    return true;
                }
            }
            else{
                if(dfsvisited[a]==1){
                    return true;
                }
            }
        }
        dfsvisited[src]=0;

        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>arr(n);
        for( auto a:pre){
            arr[a[1]].push_back(a[0]);
        }

        vector<int>visited(n,0);
        vector<int>dfsvisited(n,0);
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(dfsvisited,visited,i,arr)==true){
                    return false;
                }
            }
        }
        return true;

    }
};