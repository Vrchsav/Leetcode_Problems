class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int save=times[targetFriend][0];
        sort(times.begin(),times.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>takenseat;
        priority_queue<int,vector<int>,greater<int>>emptty;
        int current_seat=0;
        for(int i=0;i<=times.size();i++){
            int arival=times[i][0];
            int leaving=times[i][1];
            while(!takenseat.empty() && takenseat.top().first<= arival){
                emptty.push(takenseat.top().second);
                takenseat.pop();
            }
            if(emptty.empty()){
                takenseat.push({leaving,current_seat});
                if(arival==save){
                    return current_seat;
                }
                current_seat++;
            }
            else{
                int seat=emptty.top();
                if(arival==save){
                    return seat;
                }
                emptty.pop();
                takenseat.push({leaving,seat});
                

            }
            


        }
        return -1;
    }
};