class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int>save=times[targetFriend];
        sort(times.begin(),times.end());
        vector<int>arr;
        for(int i=0;i<=times.size();i++){
            int arival=times[i][0];
            int leaving=times[i][1];
            int chair=-1;
            for(int j=0;j<arr.size();j++){
                if( arr[j]<=arival){
                    arr[j]=leaving;
                    chair=j;
                    break;
                }
            }
            if(chair==-1){
                chair= arr.size();;
                arr.push_back(leaving);
                
            }
            if(arival==save[0] && leaving==save[1]){
                        return chair;
                    }

        }
        return -1;
    }
};