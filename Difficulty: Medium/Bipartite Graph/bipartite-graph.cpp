//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        queue<pair<int,int>>q;
        vector<int>visited(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            if(visited[i]==0){
            q.push({i,1});
            visited[i]=1;
            while(!q.empty()){
                            pair<int, int> top = q.front();

                int curr = top.first;
            int colour = top.second;
                q.pop();
                int nextc;
                if(colour==1){
                    nextc=2;
                }
                else{
                    nextc=1;
                }
                for(auto a:adj[curr]){
                    
                    if(visited[a]==0){
                        visited[a]=nextc;
                        q.push({a,nextc});
                        
                    }
                    else{
                        if(nextc!=visited[a]){
                            return false;
                        }
                    }
                }}
            }
        }
        return true;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends