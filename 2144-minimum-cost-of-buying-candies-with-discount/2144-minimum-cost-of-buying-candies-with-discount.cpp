class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        // <= min(one,two);
        sort(cost.begin(),cost.end());

        int sum = 0;
        for(int i=n-1;i>=0;i-=3){
            sum += cost[i];
            if(i-1>=0) sum += cost[i-1];
        }
        return sum;
    }
};