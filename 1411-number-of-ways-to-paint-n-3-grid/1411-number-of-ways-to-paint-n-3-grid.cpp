class Solution {
public:
    /*
    as column length is fixed(3), so we will fill 1st row first and then with the help of 1st row , we will be filling other rows so that max string lenght we will have is 3.
    So, for this we need to find: 
    -> for 1st row, all possible coloring string.
    -> loop for each possible coloring string 
        take one string and the fill the complete next rows and then take other again fill othe rows accordingly and similarly for all possible, so 1st row will have all the possible ways of coloring.

    */
    int mod = 1e9+7;
    vector<string>rowStates;
    vector<vector<int>>dp;
    void makeStates(string s, vector<char>&option){
        if(s.size()==3) {
            rowStates.push_back(s);
            return;
        }
        for(int i=0;i<3;i++){
            char c = option[i];
            if(!s.empty() && s.back()==c) continue;
            s.push_back(c);
            makeStates(s,option);
            s.pop_back();
        }
    }
    int solve(int prevIdx, int remRow){
        if(remRow == 0) {
            return 1;
        }
        if(dp[prevIdx][remRow]!= -1) return dp[prevIdx][remRow];
        int ways = 0;
        const string& prevStr = rowStates[prevIdx];
        for(int i=0;i<rowStates.size();i++){
            if(i == prevIdx) continue;
            const string& curr = rowStates[i];
            bool valid  = true;
            for(int j=0;j<3;j++){
                if(prevStr[j]==curr[j]) {
                    valid = false;
                    break;
                }
            }
            if(valid){
                ways = (ways + solve(i,remRow-1))%mod;
            }
        }
        return dp[prevIdx][remRow] = ways;
    }
    int numOfWays(int n) {
        vector<char>option = {'R','Y','G'};
        makeStates("",option);

        int size = rowStates.size();
        dp.assign(size,vector<int>(n,-1));

        int res = 0;
        for(int i=0;i<size;i++){
            res = (res + solve(i,n-1))%mod;
        }

        return res%mod;
    }
};