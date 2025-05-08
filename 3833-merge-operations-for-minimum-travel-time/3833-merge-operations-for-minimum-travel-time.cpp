class Solution {
public:
    int N;

    int solve(int i,int k,int currRate,vector<int>& position,vector<int>& time,vector<vector<vector<int>>>& dp){
        if(i==N-1){
            if(k>0) return INT_MAX;
            return 0;
        }
        if(dp[i][k][currRate]!=-1) return dp[i][k][currRate];
        int res = INT_MAX;
        //skip without merging
        int skipResultTime = solve(i+1,k,time[i+1],position,time,dp);
        if(skipResultTime!=INT_MAX){
            int dist = position[i+1]-position[i];
            res = min(res,dist*currRate+skipResultTime);
        }

        //we will merge
        int mergeTime = time[i+1];
        int mergeCount = 0;
        if(k>0){
            for(int j = i+2;j<N && mergeCount<k; j++){
                mergeCount ++;
                mergeTime += time[j];
                int mergeResultTime = solve(j,k-mergeCount,mergeTime,position,time,dp);
                if(mergeResultTime != INT_MAX){
                    int dist = position[j]-position[i];
                    res = min(res,dist*currRate + mergeResultTime);
                }
            }
        }
        return dp[i][k][currRate]=res;
    }
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        N=n;
        int sum = 0;
        for(auto &it:time){
            sum += it;
        }
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(sum+1,-1)));
        return solve(0,k,time[0],position,time,dp);
    }
};