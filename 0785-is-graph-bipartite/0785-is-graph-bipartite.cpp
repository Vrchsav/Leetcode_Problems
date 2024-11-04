class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> coloured(n,0);

        queue<pair<int,int>>q;
        coloured[0]=1;
        q.push({0,2});
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
};