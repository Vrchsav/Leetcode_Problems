//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>parent(n,-2);
        vector<int>visited(n,0);
        queue<int>q;
        
        for(int i=0;i<n;i++){
        if( visited[i]==0){
            q.push(i);
        visited[i]=1;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto a:adj[top]){
                if(visited[a]==0){
                    q.push(a);
                    visited[a]=1;
                    parent[a]=top;
                }
                else{
                    if(parent[top]!=a ){
                        return true;
                    }
                }
            }
        }}}
        return false;
        
        
        // Code here
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
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends