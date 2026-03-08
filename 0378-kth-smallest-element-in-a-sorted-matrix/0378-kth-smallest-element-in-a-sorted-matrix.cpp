class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low<=high){
            int mid = low+(high-low)/2;
            int row = n-1, i=0, cnt=0;
            while(i<n && row>=0){
                if(matrix[row][i]>mid) {
                    row--;
                }else{
                    cnt += (row+1);
                    i++;
                }
            }
            if(cnt>=k){
                high = mid-1;
            }else low = mid+1;
        }
        return low;
    }
};