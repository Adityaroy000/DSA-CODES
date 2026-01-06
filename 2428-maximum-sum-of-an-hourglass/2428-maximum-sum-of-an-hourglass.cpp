class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>>pre(n+1,vector<long long>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i+1][j+1] = pre[i+1][j]+pre[i][j+1]-pre[i][j]+grid[i][j];
            }
        }
        long long maxSum = 0;
        for(int i=0;i<n;i++){
            int rmin = i;
            int rmax = min(i+2,n-1);

            if(rmax-rmin+1 != 3) continue;
            for(int j=0;j<m;j++){
                int cmin = j;
                int cmax = min(j+2,m-1);

                if(cmax-cmin+1 != 3) continue;

                int midr = (rmin+rmax)/2;

                long long tsum = pre[rmax+1][cmax+1] - pre[rmax+1][cmin] - pre[rmin][cmax+1] + pre[rmin][cmin];
                long long req = tsum - grid[midr][cmin] - grid[midr][cmax];

                maxSum = max(maxSum,req);
            }
        }
        return (int)maxSum;
    }
};