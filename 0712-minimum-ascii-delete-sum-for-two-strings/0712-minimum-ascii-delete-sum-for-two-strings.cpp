class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,string &s1,string &s2){
        if(i>=s1.size() && j>=s2.size()) return 0;
        if(i>=s1.size()) return s2[j] + solve(i,j+1,s1,s2);
        if(j>=s2.size()) return s1[i] + solve(i+1,j,s1,s2);
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = solve(i+1,j+1,s1,s2);

        int del_i = s1[i] + solve(i+1,j,s1,s2);
        int del_j = s2[j] + solve(i,j+1,s1,s2);
        
        return dp[i][j] = min(del_i,del_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        dp.assign(s1.size(),vector<int>(s2.size(),-1));
        return solve(0,0,s1,s2);
    }
};