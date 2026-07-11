class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row
        for(int i=0;i<9;i++){
            unordered_set<char>st;
            for(int j=0;j<9;j++){
                if(st.count(board[i][j])) return false;
                if(board[i][j] != '.') st.insert(board[i][j]);
            }
        }
        //col
        for(int i=0;i<9;i++){
            unordered_set<char>st;
            for(int j=0;j<9;j++){
                if(st.count(board[j][i])) return false;
                if(board[j][i] != '.') st.insert(board[j][i]);
            }
        }

        //3*3 box
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                //3*3
                unordered_set<char>st;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(st.count(board[k][l])) return false;
                        if(board[k][l] != '.') st.insert(board[k][l]);
                    }
                }
            }
        }
        return true;
    }
};