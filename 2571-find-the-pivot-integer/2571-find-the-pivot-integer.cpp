#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int mySqrt(int n) {
        if (n==0) return 0;
        double x=n ,x0=1;
        while (abs(x-x0)>=1){
            x0=x;
            x=x0-(x0*x0-n)/(2*x0);
        }
        if (x<=x0) return int(x);
        else return int(x0);
    }
    int pivotInteger(int n) {
        int p=n*(n+1)/2;
        double x=mySqrt(p);
        return x*x==p?x:-1;
    }
};