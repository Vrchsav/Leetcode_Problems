class Solution {
       
    bool bsf(vector<vector<int>>& graph,int src,  vector<int> &coloured ){
        queue<pair<int,int>>q;
        coloured[src]=1;
        q.push({src,2});
        while(!q.empty()){
            pair<int,int>top=q.front();
            q.pop();
            for(auto a:graph[top.first]){
                int currentc=top.second;
                if(coloured[a]==0){
                    
                    if(currentc==1){
                    q.push({a,2});
                    
                    }
                    else{
                        q.push({a,1});
                    }
                    coloured[a]=currentc;

                }
                else{
                    if(coloured[a]!=currentc){
                        return false;
                    }
                }
            }

        }
        return true;
        
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> coloured(n,0);
        for(int i=0;i<n;i++){
            if(coloured[i]==0){
                if(!bsf(graph,i,coloured)){
                    return false;
                }
            }
        }
        return true;

        
    }
};