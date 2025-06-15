class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int l=0,r=1,maxProfit = 0;
        while(r<n){
            int profit = prices[r]-prices[l];
            if(profit<0){
                profit = 0;
                l=r;
            }else{
                maxProfit += profit;
                l++;
            }
            r++;
        }
        return maxProfit;
    }
};