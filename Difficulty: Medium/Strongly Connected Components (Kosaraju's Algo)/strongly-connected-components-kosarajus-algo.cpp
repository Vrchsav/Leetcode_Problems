//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution

{
    private:
        void dfstoposort(vector<vector<int>>& adj,stack<int>&stt,vector<int>&visited,int src){
            visited[src]=1;
            for(auto a:adj[src]){
                if(visited[a]==0){
                    dfstoposort(adj,stt,visited,a);

                }
            }
            stt.push(src);
            
        }
        void dfs(int src, vector<vector<int>>& newadj,vector<int>&visited){
            visited[src]=1;
            for(auto a:newadj[src]){
                if(visited[a]==0){
                    dfs(a,newadj,visited);

                }
            }
            
        }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int>stt;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
        dfstoposort(adj,stt,visited,i);}
        
        }
        vector<vector<int>> newadj(V);
        for(int i=0;i<V;i++){
            for(auto a:adj[i]){
                newadj[a].push_back(i);
            }
        }
        int ans=0;
        for(int i=0;i<V;i++){
            visited[i]=0;
        }
        
        while(!stt.empty()){
            int top=stt.top();
            stt.pop();
            if(visited[top]==0){
                ans++;
                dfs(top,newadj,visited);
            }
            
        }
        
        return ans;
        
        
        
        
        
        
     
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends