class Solution {
public:
    int val= 0;
    void solve(int row,int col,int size,vector<vector<int>>& grid){
        if(size == 1){
            grid[row][col] = val++;
            return;
        }
        int subgrid = size/2;
        solve(row,col+subgrid,subgrid,grid);
        solve(row+subgrid,col+subgrid,subgrid,grid);
        solve(row+subgrid,col,subgrid,grid);
        solve(row,col,subgrid,grid);
    }
    vector<vector<int>> specialGrid(int N) {
        int n = 1<<N;
        vector<vector<int>>grid(n,vector<int>(n));

        solve(0,0,n,grid);
        return grid;
    }
};