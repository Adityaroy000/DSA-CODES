class Solution {
public:
    int m,n;
    vector<vector<int>>vis;
    void bfs(int row, int col, vector<vector<char>>& board){
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        queue<pair<int,int>>q;
        vis[row][col] = 1;
        q.push({row,col});

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O' && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vis.resize(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j] && (i==0 || j==0 || i==m-1||j==n-1)){
                    bfs(i,j,board); 
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] == 0 && board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
};