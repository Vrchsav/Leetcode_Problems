class Solution {
private:
    int countDistinct(string str)
{
    int freq = 0;
    int n = str.size();
    for (int i = 0; i < n; i++) {
        int curr_pos = str[i] - 'a';
        freq = freq | (1 << curr_pos);
    }
    int ans = 0;
    while (freq != 0) {
        if ((freq & 1) == 1)
            ans++;
        freq = freq >> 1;
    }
    return ans;
}
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        vector<string> send;
        set<char> a;
        for(int i=0 ;i<s.size()-2;i++){
            if(a.find(s[i])!=a.end()){
                continue;
            }
            for(int j=s.size()-1;j>i+1;j--){
                if(s[i]==s[j]){
                    ans+=countDistinct( s.substr(i+1,j-(i+1)));
                    a.insert(s[i]);
                    break;
                }
            }
        }
        return ans;
    }
};