class Solution {
public: 
    int mod = 1e9+7;
    vector<string>columnStates;
    void generateColumnStates(string curr,int len,char prevChar,int m){
        if(len==m){
            columnStates.push_back(curr);
            return;
        }
        for(char ch:{'R','G','B'}){
            if(ch==prevChar) continue;
            generateColumnStates(curr+ch,len+1,ch,m);
        }
    }

    int solve(int m,int prevcol,int remcol,vector<vector<int>>& dp){
        if(remcol == 0) return 1;

        string prev = columnStates[prevcol];
        int ways = 0;

        if(dp[prevcol][remcol]!=-1) return dp[prevcol][remcol];

        for(int i=0;i<columnStates.size();i++){
            string curr = columnStates[i];
            bool valid = true;
            for(int j=0;j<m;j++){
                if(curr[j]==prev[j]) {
                    valid = false;
                    break;
                }
            }
            if(valid){
                ways = (ways+solve(m,i,remcol-1,dp))%mod;
            }
        }
        return dp[prevcol][remcol] = ways;
    }

    int colorTheGrid(int m, int n) {
        generateColumnStates("",0,'#',m);
        int res = 0;
        int totsalstates = columnStates.size();
        vector<vector<int>>dp(totsalstates,vector<int>(n,-1));
        for(int col = 0;col<columnStates.size();col++){
            res = (res+solve(m,col,n-1,dp))%mod;
        }

        return res;
    }
};