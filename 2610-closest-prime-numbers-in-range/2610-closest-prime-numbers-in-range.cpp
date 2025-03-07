class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool>isPrime(right+1,true);
        isPrime[0]=0;
        isPrime[1]=0;

        for(int i=2;i<=sqrt(right);i++){
            if(isPrime[i]){
                for(int j=2;i*j<=right;j++){
                    isPrime[i*j]=0;
                }
            }
        }

        vector<int>num;
        for(int i=0;i<=right;i++){
            if(isPrime[i] && i>=left){
                num.push_back(i);
            }
        }
       int a=-1;
       int b=-1;
       int sub=INT_MAX;
         for(int i=1;i<num.size();i++){
            
            if(sub>num[i]-num[i-1]){
                sub=num[i]-num[i-1];
                a=num[i-1];
                b=num[i];

            }
            
        
            
        }
        return {a,b};




        
        
    }
};