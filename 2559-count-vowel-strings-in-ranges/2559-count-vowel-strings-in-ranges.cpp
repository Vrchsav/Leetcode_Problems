class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> hash;
        int count = 0;
        set<char> stt = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < words.size(); i++) {
            int lst = words[i].size() - 1;
            if (stt.find(words[i][0]) != stt.end() &&
                stt.find(words[i][lst]) != stt.end()) {
                count++;
            }
            hash.push_back(count);
        }
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            int s = queries[i][0];
            int e = queries[i][1];
            if(s-1>=0){
            ans.push_back(hash[e] - hash[s-1]);}
            else{
                ans.push_back(hash[e] );
            }
        }
        return ans;
    }
};