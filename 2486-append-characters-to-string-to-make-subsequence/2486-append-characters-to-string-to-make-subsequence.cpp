class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
        int s_size=s.size();
        int t_size=t.size();

        while(i<s_size && j<t_size){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j==t_size){
            return 0;
        }
        else{
            return t_size-j;
        }

        
    }
};