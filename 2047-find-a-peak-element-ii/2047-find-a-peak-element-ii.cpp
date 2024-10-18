class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>ans;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m;j++){
                bool ispeak = true;
                if(i>0&&mat[i][j]<mat[i-1][j]) ispeak= false;
                if(j>0&&mat[i][j]<mat[i][j-1]) ispeak = false;
                if(i<n-1&&mat[i][j]<mat[i+1][j]) ispeak = false;
                if(j<m-1&&mat[i][j]<mat[i][j+1]) ispeak = false;
                if(ispeak){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};