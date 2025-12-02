class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int top = 0,bot = n-1,left = 0,right = n-1;
        int num = 1;

        while(top<=bot && left<=right){
            for(int i=left;i<=right;i++){
                matrix[top][i] = num;
                num++;
            }
            top++;
            for(int i=top;i<=bot;i++){
                matrix[i][right] = num;
                num++;
            }
            right--; 
            if(top<=bot){
                for(int i=right;i>=left;i--){
                    matrix[bot][i] = num;
                    num++;
                }
                bot--;
            }
            if(left<=right){
                for(int i=bot;i>=top;i--){
                    matrix[i][left] = num;
                    num++;
                }
                left++;
            }
        }
        return matrix;
    }
};