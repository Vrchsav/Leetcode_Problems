class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& g, string d) {
        map<int,int>mpp;
        for(int i = 0; i < p.size(); i++) {  
                mpp[p[i]]=i;
            
        }
        stack<int>stt;
        map<int,int>::iterator it;
        vector<int> ans;
        for (it = mpp.begin(); it != mpp.end(); ++it) {
            int index=it->second;
            if(d[index]=='R'){
                stt.push(index);
            }
            else{
                
                
                while(!stt.empty()&& g[index]>0){
                    int front_idx=stt.top();
                    stt.pop();
                
               
                if(g[index]>g[front_idx]){
                    g[front_idx]=0;
                    g[index]--;
                }
                else if( g[index]<g[front_idx]){
                    g[front_idx]--;
                    stt.push(front_idx);
                    g[index]=0;
                }
                else{
                    g[front_idx]=0;
                    g[index]=0;
                }}
            }
        }
        for(int i=0;i<g.size();i++){
            if(g[i]!=0){
                ans.push_back(g[i]);
            }
        }
        return ans;
    }
};