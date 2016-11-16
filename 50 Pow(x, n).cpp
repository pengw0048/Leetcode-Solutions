class Solution {
public:
    double myPow(double x, long long n) {
        if(n<0)return 1/myPow(x,-(long long)n);
        if(n==0)return 1;
        if(n==1)return x;
        double h=myPow(x,n/2);
        if(n%2==0)return h*h;
        else return h*h*x;
    }
};