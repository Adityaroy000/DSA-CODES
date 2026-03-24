class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = board.size();
        int c = board[0].size();
        int u = click[0],v=click[1];

        if(board[u][v] == 'M') {
            board[u][v] = 'X';
            return board;
        }

        int drow[] = {-1,-1,-1, 0, 0, 1, 1, 1};
        int dcol[] = {-1, 0, 1,-1, 1,-1, 0, 1};

        queue<pair<int,int>>q;
        vector<vector<int>>vis(r,vector<int>(c,0));


        q.push({u,v});
        vis[u][v] = 1;

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            int cnt = 0;
            for(int i=0;i<8;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];

                if(nrow>=0 && nrow<r && ncol>=0 && ncol<c){
                    if(board[nrow][ncol]=='M') cnt++;
                }
            } 
            if(cnt>0){
                board[row][col] = cnt+'0';
            }else{
                board[row][col] = 'B';
                for(int i=0;i<8;i++){
                    int nrow = row+drow[i];
                    int ncol = col+dcol[i];

                    if(nrow>=0 && nrow<r && ncol>=0 && ncol<c && !vis[nrow][ncol]){
                       q.push({nrow,ncol});
                       vis[nrow][ncol] = 1;
                    }
                } 
            }
        }
        return board;
    }
};