class Solution {
public:
    int m,n;
    void bfs(int row,int col, vector<vector<char>>& board){
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='X'){
                    q.push({nr,nc});
                    board[nr][nc] = '.';
                }
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    ans ++;
                    bfs(i,j,board);
                }
            }
        }

        return ans;
    }
};