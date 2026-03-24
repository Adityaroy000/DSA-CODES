class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 1) matrix[i][j] += matrix[i-1][j];
            }
        }

        for(int i=0;i<m;i++){
            sort(matrix[i].begin(),matrix[i].end(),greater<int>());
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            int currarea = 0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0) break;
                currarea = matrix[i][j]*(j+1);
                ans = max(ans,currarea);
            }
        }

        return ans;
    }
};