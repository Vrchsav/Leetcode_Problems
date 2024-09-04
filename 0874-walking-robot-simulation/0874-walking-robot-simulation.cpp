class Solution {
private:
    void mapping(vector<vector<int>> obstacles, map<int, set<int>>& mpp) {
    for (int i = 0; i < obstacles.size(); i++) {
        int x = obstacles[i][0];
        int y = obstacles[i][1];
        mpp[x].insert(y);
    }
    return;
}
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>>news={{0,1},{1,0},{0,-1},{-1,0}};
        vector<int>curr_pos={0,0};
        int ans=-1;
        int direction=0;
        map<int, set<int>> mpp;
        mapping(obstacles,mpp);

        for(auto command:commands){
            if(command==-1){
                direction++;
                direction=direction%4;
            }
            else if(command==-2){
                direction--;
                if(direction==-1){
                    direction=3;
                }
            }
            else{
                for(int st=0;st<command;st++){
                    int next_x=curr_pos[0]+news[direction][0];
                    int next_y=curr_pos[1]+news[direction][1];
                    if(mpp.find(next_x)!=mpp.end() && mpp[next_x].find(next_y)!=mpp[next_x].end()){
                        break;
                    }
                    curr_pos[0]=next_x;
                    curr_pos[1]=next_y;

                }
            }
            ans=max(ans,int(pow(curr_pos[0],2) + pow(curr_pos[1],2)));
        }
return ans;

    }
};