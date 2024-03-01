class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one_count=0;
        int zero_count=0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='1'){
                one_count++;
            }
            else
            zero_count++;
        }
        if(zero_count==0 || one_count==0 ){
            return s;
        }
        string ans="";
        while(one_count!=1){
            ans+='1';
            one_count--;
        }
        while(zero_count!=0){
            ans+='0';
            zero_count--;
        }
         ans+='1';
         return ans;

    }
};