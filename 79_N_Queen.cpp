// http://rb.gy/n9fw8

bool isSafe(int row, int col, vector<vector<int>> &board, int n){

    int dup_row = row;

    int dup_col = col;

 

    //first case

    while(dup_col>=0){

        if(board[row][dup_col] == 1) return false;

        dup_col--;

    }

 

    //second case-->first diagonal;

    dup_col = col;

    dup_row = row;

    while(dup_col>=0 && dup_row>=0){

        if(board[dup_row][dup_col] == 1)return false;

        dup_row--;

        dup_col--;

    }

 

    //third case-->second diagonal;

    dup_col = col;

    dup_row = row;

    while(dup_col>=0 && dup_row<n){

        if(board[dup_row][dup_col] == 1)return false;

        dup_row++;

        dup_col--;   

    }

 

    return true;

}

void addBoard(vector<vector<int>> &board, vector<vector<int>> &res){

    vector<int> temp;

    int n = board.size();

    

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            temp.push_back(board[i][j]);

        }

    }

 

    res.push_back(temp);

}

void solve(int col, vector<vector<int>> &board, vector<int> &flatten, vector<vector<int>> &ans, int n){

    //base case;

    vector<int> temp;

    if(col == n){

        addBoard(board, ans);

        return;

    }

 

    for(int row=0; row<n; row++){

        if(isSafe(row, col, board, n)){

            board[row][col] = 1;

            solve(col+1, board, flatten, ans, n);

            board[row][col] = 0;

        }

    }

}

 

vector<vector<int>> solveNQueens(int n) {

    // Write your code here.

    vector<vector<int>> ans;

    vector<vector<int>> board(n, vector<int>(n, 0));

    vector<int> flatten;

    

 

    solve(0, board, flatten,  ans, n);

 

    return ans;

 

}

