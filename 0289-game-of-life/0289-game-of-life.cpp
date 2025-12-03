class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> copy = board;

        int drow[] = {-1,-1,0,1,1,1,0,-1};
        int dcol[] = {0,1,1,1,0,-1,-1,-1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cr = i;
                int cc = j;
                int cnt = 0;
                for(int k = 0;k<8;k++){
                    int ncr = cr+drow[k];
                    int ncc = cc+dcol[k];
                    if(ncr<m&&ncr>=0 && ncc<n && ncc>=0 && copy[ncr][ncc]==1) cnt++;
                }
                if(copy[i][j]==1){
                    if(cnt < 2 || cnt>3) {
                        //dies by under or over
                        board[i][j]=0;
                    }else{
                        //live for next gen
                        board[i][j] = 1;
                    }
                }else{
                    if(cnt == 3){
                        //become live 
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};