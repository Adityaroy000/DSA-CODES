class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        int maxLen = 0;
        vector<vector<int>>pre(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i+1][j+1] = pre[i+1][j]+pre[i][j+1]-pre[i][j] + mat[i][j];
            }
        }
        
        int low = 1,high = min(n,m);

        while(low<=high){
            int mid = (low+high)/2;

            bool flag = false;
            for(int i=0;i+mid<=n;i++){
                bool valid = false;
                for(int j=0;j+mid<=m;j++){ 
                    int sum = pre[i+mid][j+mid]-pre[i+mid][j]-pre[i][j+mid]+pre[i][j];
                    if(sum <= threshold){
                        valid = true;
                        break;
                    }
                }
                if(valid){
                    maxLen = max(maxLen,mid);
                    low = mid+1;
                    flag = true;
                    break;
                }
            }
            if(!flag) high = mid-1;
        }
        return maxLen;
    }
};