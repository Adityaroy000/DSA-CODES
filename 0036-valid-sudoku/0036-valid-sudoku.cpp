class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        for(int i=0;i<n;i++){
            unordered_map<char,int>mpp;
            for(int j=0;j<n;j++){
               if(board[i][j] != '.') mpp[board[i][j]]++;
            }
            for(auto &it:mpp){
                if(it.second>1){
                    return false;
                }
            }
        }
        for(int i=0;i<n;i++){
            unordered_map<char,int>mpp;
            for(int j=0;j<n;j++){
               if(board[j][i] != '.') mpp[board[j][i]]++;
            }
            for(auto &it:mpp){
                if(it.second>1){
                    return false;
                }
            }
        }
        int r = 0,c=0;
        while(r<9){
            c=0;
            while(c<9){
                int i = c;
                int j = i+2;
                unordered_map<char,int>mpp;
                for(int row=r;row<=r+2;row++){
                    for(int col=i;col<=j;col++){
                        if(board[row][col]!='.') mpp[board[row][col]]++;
                    }
                }
                for(auto & it: mpp){
                    if(it.second>1) return false;
                }
                c+=3;
            }
            r+=3;
        }
        return true;
    }
};