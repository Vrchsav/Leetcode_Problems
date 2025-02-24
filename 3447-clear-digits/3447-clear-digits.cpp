class Solution {
public:
    string clearDigits(string s) {
        bool flag =true;
        while(flag){
            flag =false;
            int index_str=-1;
            for(int i=0;i<s.size();i++){
                if(isdigit(s[i]) && index_str!=-1){
                    s.erase(s.begin()+i);
                    s.erase(s.begin()+index_str);
                    flag=true;
                    break;

                }else{
                    if(!isdigit(s[i]))
                    index_str=i;
                }
            }
        }
        return s;
        
    }
};