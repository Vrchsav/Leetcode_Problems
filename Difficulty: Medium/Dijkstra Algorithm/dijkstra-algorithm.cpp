//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template

struct comparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second > b.second; // Greater than for min-heap behavior (compare by second element)
    }
};

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n=adj.size();
        vector<int>distance(n,INT_MAX);
       
        distance[src]=0;
        priority_queue<pair<int,int>, std::vector<pair<int,int>>,comparator>q;
        q.push({src,0});
        while(!q.empty()){
            pair<int,int>top=q.top();
            q.pop();
            for(auto a:adj[top.first]){
                if((a.second+top.second)<distance[a.first]){
                    distance[a.first]=a.second+top.second;
                    q.push({a.first,distance[a.first]});
                }
            }
        }
        
        return distance;
        // Code here
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends