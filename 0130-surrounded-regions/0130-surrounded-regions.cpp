class Solution {
private: 
    void dfs(int row,int col,int drow[],int dcol[],vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[row][col] = 1;
        for(int i = 0; i<4; i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            if(nrow<board.size() && nrow>=0 && ncol<board[0].size() && ncol>=0 && board[nrow][ncol]=='O'&&vis[nrow][ncol]==0){
                dfs(nrow,ncol,drow,dcol,vis,board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        vector<vector<int>>vis(r,vector<int>(c,0));
        //first and last row
        for(int j = 0; j<c; j++){
            if(board[0][j]=='O' && vis[0][j]==0){
                dfs(0,j,drow,dcol,vis,board);
            }
            if(board[r-1][j]=='O' && vis[r-1][j]==0){
                dfs(r-1,j,drow,dcol,vis,board);
            }
        }
        // first and last column
        for(int i = 0; i<r; i++){
            if(board[i][0]=='O'&&vis[i][0]==0){
                dfs(i,0,drow,dcol,vis,board);
            }
            if(board[i][c-1]=='O'&&vis[i][c-1]==0){
                dfs(i,c-1,drow,dcol,vis,board);
            }
        }
        
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(vis[i][j]==0 && board[i][j]!='X'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};