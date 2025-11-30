class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0;

        int l =0, r = 1;
        while(r<n){
            if(prices[r] != prices[r-1]-1){
                long long len = r-l;
                ans += (len*(len+1))/2;
                l = r;
            }
            r++;
        }
        if(l<n){
            long long len = r-l;
            ans += (len*(len+1))/2;
        }
        return ans;
    }
};