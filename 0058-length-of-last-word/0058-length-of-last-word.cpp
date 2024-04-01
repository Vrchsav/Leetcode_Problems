class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        int count=0;
        
        if(s[i]==' '){
            while(true){
                i--;
                if(s[i]!=' ')
                break;
            }}



            while(true){
                count++;
                i--;
                if( i>=s.size()||s[i]==' ' ){
                    return count;
                }

            }
       
        
        return count;
}
    
};