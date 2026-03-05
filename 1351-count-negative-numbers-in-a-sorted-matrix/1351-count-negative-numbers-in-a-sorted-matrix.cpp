class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        int row = r-1, cnt = 0;
        int i=0;
        while(i<c){
            if(row>=0 && grid[row][i] < 0){
                row--;
                cnt += (c-i);
            }else i++;
        }
        return cnt;
    }
};