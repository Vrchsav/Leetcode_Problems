class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total_time=0;
        double sum=0;
        for(int i=0;i<customers.size();i++){
            double arival=customers[i][0];
            double time=customers[i][1];
            if(total_time<arival){
            sum+=time;
            total_time=(arival+time);
            }
            else{
                total_time+=time;
                sum+=total_time-arival;
            }
            
            
        }
        double ans=double(sum)/double(customers.size());
        return ans;
        
    }
};