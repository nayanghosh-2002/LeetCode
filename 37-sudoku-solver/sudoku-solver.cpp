class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,board.size());
    }

    bool solve(vector<vector<char>>& board,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    for(char num='1';num<='9';num++){
                        if(isValid(board,i,j,num)){
                            board[i][j]=num;
                            if(solve(board,n))return true;
                            else board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board,int row,int col,char num){
        for(int i=0;i<9;i++){
            if(board[row][i]==num)return false;
            if(board[i][col]==num)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==num)return false;
        }
        return true;
    }
};