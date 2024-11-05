//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(int i=0;i<m;i++){
                adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
                adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
                
            
        }
        vector<int>path(n+1,INT_MAX);
        path[1]=0;
        vector<int>parent(n+1,-1);
        parent[1]=-1;
        set<pair<int,int>>stt;
        stt.insert({0,1});
        while(!stt.empty()){
            auto it=*(stt.begin());
            int node=it.second;
            int distance=it.first;
            stt.erase(it);
            for(auto a:adj[node]){
                if(distance+a.second<path[a.first]){
                    if(path[a.first]!=INT_MAX){
                        stt.erase({path[a.first],a.first});
                    }
                    parent[a.first]=node;
                    path[a.first]=distance+a.second;
                    stt.insert({path[a.first],a.first});
                }
                
            }
        }
        if(path[n]==INT_MAX){
            return {-1};
        }
        vector<int>ans;
        
        
        int i=n;
        ans.push_back(n);

        while(true){
            if(parent[i]==-1){
                break;
            }
            ans.push_back(parent[i]);
            i=parent[i];
            
        }
        ans.push_back(path[n]);
        std::reverse(ans.begin(), ans.end());


        return ans;
            // Code here
    }
};



//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends