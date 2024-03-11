class Solution {
public:
    string customSortString(string order, string s) {
        vector<int >map(26,0);
        for(int i=0;i<s.size();i++){
            map[s[i]-'a']++;
        }
        string stt="";
        for(int i=0;i<order.size();i++){
            while(map[order[i]-'a']>0){
                stt+=order[i];
                map[order[i]-'a']--;
            }}
           
            
         for(int i=0;i<26;i++){
            while(map[i]>0){
                stt+=char('a'+i);
                map[i]--;
                
            }
            
        }
        return stt;
    }
};