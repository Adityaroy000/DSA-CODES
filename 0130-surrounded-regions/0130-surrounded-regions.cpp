class Solution {
public:
    int m,n;
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[row][col] = 1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrid = row+drow[i];
            int ncid = col+dcol[i];
            if(nrid<m&&nrid>=0&&ncid<n&&ncid>=0&&board[nrid][ncid]=='O'&&vis[nrid][ncid]==0){
                dfs(nrid,ncid,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        
        vector<vector<int>>vis(m,vector<int>(n,0));

        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i== m-1 || j==0 || j==n-1) && board[i][j]=='O'&&vis[i][j]==0){
                    dfs(i,j,vis,board);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};