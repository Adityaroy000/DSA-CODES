class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();

        vector<int>diff(1001);
        int maxt = INT_MIN;
        for(int i=0;i<n;i++){
            int pass = trips[i][0];
            int f = trips[i][1];
            int t = trips[i][2];
            maxt = max(maxt,t);

            diff[f] += pass;
            diff[t] -= pass;
        }
        int sum = 0;
        for(int i=0;i<=maxt;i++){
            sum += diff[i];
            diff[i] = sum;
            if(diff[i]>capacity) return false;
        }
        return true;

    }
};