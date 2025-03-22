class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int>prevrow (n,0);

        for(int i =0;i<m; i++){
            vector<int>temp(n,0);
            for(int j = 0;j<n; j++){
                if(i == 0&& j== 0 && obstacleGrid[i][j] != 1) temp[j] = 1;
                else if(i == 0&& j== 0 && obstacleGrid[i][j] == 1) temp[j] = 0;
                else if(obstacleGrid[i][j] == 1) temp[j] = 0;
                else{
                    int up=0,left=0;
                    if(i>0) up = prevrow[j];
                    if(j>0) left = temp[j-1];
                    temp[j] = up+left;
                }
            }
            prevrow = temp;
        }
        return prevrow[n-1];
    }
};