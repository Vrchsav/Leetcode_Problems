class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> mpp;
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }
        priority_queue<pair<char, int>> q;

        for (auto it = mpp.begin(); it != mpp.end(); it++) {
            q.push({ it->first,it->second});
        }
        string ans = "";
        pair<char,int>hold={'#',-1};
        while (!q.empty()) {

            auto [charcter,count ] = q.top();
            q.pop();
            if(hold.second!=-1){
                q.push(hold);
                hold={'#',-1};
            }
            if (count > repeatLimit) {
                count = count - repeatLimit;
                string temp = string(repeatLimit, charcter);
                ans += temp;
                hold={charcter,count };
            } else {
                string temp = string(count, charcter);
                ans += temp;
            }
        }
        return ans;
    }
};