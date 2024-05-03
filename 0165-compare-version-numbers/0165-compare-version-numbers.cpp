class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i=0;
        int j=0;
        string num_i="";
        string num_j="";

        while(i<version1.size() && j<version2.size()){
           while(version1[i]!='.' && i<version1.size()){
            num_i+=version1[i];
            i++;
           }

           while(version2[j]!='.' && j<version2.size()){
            num_j+=version2[j];
            j++;
           }

           cout<<num_i<<" "<<num_j <<endl;
           if(stoi(num_i)>stoi(num_j)){
            return(1);
           }
           else if(stoi(num_i)<stoi(num_j)){
            return(-1);
           }
           i++;
           j++;
           num_i="";
           num_j="";
        }
        
        num_i="";
        num_j="";
        
        while(i<version1.size()){
            while(version1[i]!='.' && i<version1.size()){
            num_i+=version1[i];
            i++;
           }
           if(stoi(num_i)!=0){
            return(1);
           }
           i++;
        }
        while(j<version2.size()){
            while(version2[j]!='.' && j<version2.size()){
            num_j+=version2[j];
            j++;
           }
           if(stoi(num_j)!=0){
            return(-1);
           }
           j++;
        }
        return 0;
    }
};