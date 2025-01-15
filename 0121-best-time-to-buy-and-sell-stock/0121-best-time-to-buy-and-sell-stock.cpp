class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0,mini = prices[0];
        for(int i = 0;i<n; i++){
            int p = prices[i]-mini;
            maxprofit = max(maxprofit,p);
            mini = min(mini,prices[i]);
        }
        return maxprofit;
    }
};