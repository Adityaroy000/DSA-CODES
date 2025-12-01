class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int>ans;

        int top = 0,bot = m-1,left = 0,right = n-1;

        while(top<=bot && left<=right){
            //left to right
            for(int l = left;l<=right;l++){
                ans.push_back(matrix[top][l]);
            }
            top++;
            for(int i=top;i<=bot;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bot){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bot][i]);
                }
                bot--;
            }
            if(left<=right){
                for(int i=bot;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};