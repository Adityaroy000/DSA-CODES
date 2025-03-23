class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<int>lastrow(m,0),temp(m,0);
        for(int i = 0;i<n;i++){
            lastrow[i] = triangle[m-1][i];
        }
        for(int i = m-2;i>=0; i--){
            for(int j = i;j>=0; j--){
                int up = triangle[i][j] + lastrow[j];
                int diag = triangle[i][j] + lastrow[j+1];
                temp[j]= min(up,diag);
            }
            lastrow = temp;
        }

        return lastrow[0];
    }
};