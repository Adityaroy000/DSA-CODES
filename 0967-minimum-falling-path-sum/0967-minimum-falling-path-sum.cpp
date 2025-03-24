class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 1e9;
        vector<int>prevrow(n),temp(n);
        for(int i =0;i<n; i++){
            prevrow[i] = matrix[0][i];
        }
        
        for(int i = 1;i<n; i++){
            for(int j = 0;j<n; j++){
                int up = matrix[i][j] + prevrow[j];
                int rdiag = 1e9,ldiag = 1e9;
                if(j+1 < n) rdiag = matrix[i][j] + prevrow[j+1];
                if(j-1 >= 0) ldiag = matrix[i][j] + prevrow[j-1];
                temp[j] = min(up,min(rdiag,ldiag));
            }
            prevrow = temp;
        }
        int mini = prevrow[0];
        for(int i = 0;i<n; i++){
            if(mini > prevrow[i]){
                mini =prevrow[i];
            }
        }
        return mini;
    }
};