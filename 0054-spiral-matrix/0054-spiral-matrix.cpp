class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int right = m-1,left=0,top=0,bot=n-1;
        vector<int>temp;
        while(left<=right && top<=bot){
            for(int i=left;i<=right;i++){
                temp.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bot;i++){
                temp.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bot){
                for(int i=right;i>=left;i--){
                    temp.push_back(matrix[bot][i]);
                }
            }
            bot--;
            if(left<=right){
                for(int i=bot;i>=top;i--){
                    temp.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return temp;
    }
};