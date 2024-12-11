//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool solve(vector<vector<int>>& adj,vector<int>&visited,set<int>&stt,int src){
        visited[src]=1;
        stt.insert(src);

        
        for(auto a:adj[src]){
            if(visited[a]==0){
                visited[a]=1;
                if(solve(adj,visited,stt,a)){
                    return true;
                }
            }
            else if (stt.find(a)!=stt.end()){
                return true;
            }
        }
                        stt.erase(src);

        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int>visited(V,0);
        set<int>stt;
        bool ans=false;
        for(int i=0;i<V;i++){
            if(solve( adj,visited,stt,i)){
                return true;
            }
        
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends