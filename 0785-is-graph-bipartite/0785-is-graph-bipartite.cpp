class Solution {
       
    bool bsf(vector<vector<int>>& graph,int src,  vector<int> &coloured ){
        queue<int>q;
        coloured[src]=1;
        q.push(src);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto a:graph[top]){
                int currentc=coloured[top];
                if(coloured[a]==0){
                    if(currentc==1){
                        coloured[a]=2;
                    }
                    else{
                        coloured[a]=1;
                    }
                    q.push(a);

                }
                else{
                    if(coloured[a]==currentc){
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