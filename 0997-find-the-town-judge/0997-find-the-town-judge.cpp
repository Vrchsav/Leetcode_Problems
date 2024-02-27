class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int,int>>mapp(n+1,{0,0});
        for(auto a:trust){
            mapp[a[1]].first++;
            mapp[a[0]].second++;
        }
        for(int i=1;i<=n;i++){
            if(mapp[i].first==n-1  && mapp[i].second==0){
                return i;
            }
        }
        return -1;
    }
};