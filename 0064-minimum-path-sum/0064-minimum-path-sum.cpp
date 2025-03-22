class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long>prevrow(n);
        for(int i = 0;i<m ;i++){
            vector<long long>temp(n);
            for(int j =0;j<n; j++){
                if(i==0 && j == 0) temp[j] = grid[i][j];
                else{
                    long long upsum =1e9 , leftsum = 1e9;
                    if(i>0) upsum = grid[i][j] +prevrow[j];
                    if(j>0) leftsum = grid[i][j] +temp[j-1];
                    
                    temp[j] = min(upsum,leftsum);
                }
            }
            prevrow = temp;
        }
        return prevrow[n-1];
    }
};