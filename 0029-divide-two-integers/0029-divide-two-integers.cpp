class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool sign = true;
        if(dividend>=0 && divisor<0) sign = false;
        else if(dividend<=0&&divisor>0) sign = false;
        long long d = abs((long long)divisor);
        long long n = abs((long long)dividend);
        long long ans = 0;
        while(n>=d){
            int cnt = 0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            ans += (1<<cnt);
            n = n-(d<<cnt);
        }
        if(ans == (1<<31)&&sign) return INT_MAX;
        else if(ans == (1<<31) && !sign) return INT_MIN;
        if(sign) return ans;
        else return -(ans);
    }
};