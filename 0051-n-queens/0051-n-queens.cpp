class Solution {
private:
    bool isSafe( int row,int col, vector<string>&board,int n){
        int duprow=row;
        int dupcol=col;
        while(duprow>=0&& dupcol>=0){
            if(board[duprow][dupcol]=='Q'){
                return false;
            }
            
            duprow--;
            dupcol--;
        }
        dupcol=col;
        duprow=row;
        while(dupcol>=0){
            if(board[duprow][dupcol]=='Q'){
                return false;
            }
            dupcol--;
        }
        dupcol=col;
        duprow=row;
        while(duprow<n && dupcol>=0){
            if(board[duprow][dupcol] =='Q'){
                return false;
            }
            duprow++;
            dupcol--;
        }
        return true;

    }
    void solve(int col, vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,col,board,n)){
                board[i][col]='Q';
                solve(col+1,board,ans,n);
                board[i][col]='.';
            }
        }
        
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        solve(0,board,ans,n);

        return ans;
    }
};