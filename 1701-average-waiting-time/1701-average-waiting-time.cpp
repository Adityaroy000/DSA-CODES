class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        int ct = 0;
        long long sum = 0;
        for(int i=0;i<n;i++){
            int at = customers[i][0];
            int bt = customers[i][1];
            int tt = 0;
            if(at < ct){
                int wt = ct-at;
                tt = at+wt+bt;
                sum += (tt-at);
            }else{
                ct = at;
                tt = ct+bt;
                sum += (tt-at);
            }

            ct = tt;
        }
        double ans = (double)sum/n;

        return ans;
    }
};