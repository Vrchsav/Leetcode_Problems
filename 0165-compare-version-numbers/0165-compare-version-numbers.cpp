class Solution {
public:
    int compareVersion(string version1, string version2) {
        string ver1=""; 
        string ver2="";
        int i=0;
        int j=0;
        int ans=0;
        while(i<version1.size() && j<version2.size()){
            while(i<version1.size() && version1[i]!='.'){
                ver1+=version1[i];
                i++;
            }
            while(j<version2.size() && version2[j]!='.'){
                ver2+=version2[j];
                j++;
            }
            int num1=stoi(ver1);
            int num2=stoi(ver2);
            ver1="";
            ver2="";
            if(num1<num2){
                return -1;
            }
            else if (num2<num1){
                return 1;
            }
            i++;
            j++;
        }
        
        while(i<version1.size() && version1[i]!='.'){
                ver1=version1[i];
                if(stoi(ver1)!=0){
                    return 1;
                }
                i++;
            }
        while(j<version2.size() && version2[j]!='.'){
                ver1=version2[j];
                if(stoi(ver1)!=0){
                    return -1;
                }
                ver2+=version2[j];
                j++;
            }
            return 0;

    }
};