class Solution {
public:
    pair<int,int>idx(int next,int n){
        int row = n-1-(next-1)/n;
        int col;
        if((n-1-row)%2==0){
            col = (next-1)%n;
        }else{
            col = n-1-(next-1)%n;
        }
        return {row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        vector<int>vis(n*n+1,0);
        queue<pair<int,int>>q;
        q.push({1,0});
        vis[1] = 1;

        while(!q.empty()){
            auto& it = q.front();
            int curr = it.first;
            int step = it.second;
            q.pop();

            if(curr == (n*n)) return step;

            for(int move = 1;move<=6;move++){
                int next = move+curr;
                if(next > (n*n)) break;

                auto [r,c] = idx(next,n);
                int dest;
                if(board[r][c] == -1) dest = next;
                else dest = board[r][c];

                if(!vis[dest]){
                    vis[dest]=1;
                    q.push({dest,step+1});
                }
            }

        }
        return -1;
    }
};