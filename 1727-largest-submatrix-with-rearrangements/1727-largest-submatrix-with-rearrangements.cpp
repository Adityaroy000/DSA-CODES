class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>pre(m+1,vector<int>(n,0));

        for(int i=1;i<=m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i-1][j]!=0) pre[i][j] = pre[i-1][j] + 1;
            }
        }

        for(int i=1;i<=m;i++){
            sort(pre[i].begin(),pre[i].end(),greater<int>());
        }
        int ans = 0;
        for(int i=1;i<=m;i++){
            int currarea = 0;
            for(int j=0;j<n;j++){
                if(pre[i][j]==0) break;
                currarea = pre[i][j]*(j+1);
                ans = max(ans,currarea);
            }
        }

        return ans;
    }
};