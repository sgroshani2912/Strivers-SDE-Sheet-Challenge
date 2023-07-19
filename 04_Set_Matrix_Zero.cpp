// Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

//Brute force approach , TC = O((N*M)*(N+M)) + O(N*M), SC = O(1)

#include <bits/stdc++.h>

void set_row(int curr_row, int col, vector<vector<int>> &matrix){
	for(int i=0; i<col; i++){
		if(matrix[curr_row][i] != 0){
			matrix[curr_row][i] = -1;
		}
		
	}

}

void set_col(int row, int curr_col, vector<vector<int>> &matrix){
	for(int i=0; i<row; i++){
		if(matrix[i][curr_col] != 0){
			matrix[i][curr_col] = -1;
		}
	}

}
void setZeros(vector<vector<int>> &matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(matrix[i][j]==0){
				set_row(i, col, matrix);
				set_col(row, j, matrix);
			}
		}
	}
	for(int i=0;i<row;i++){
		for(int j=0; j<col; j++){
			if(matrix[i][j] == -1){
				matrix[i][j] = 0;
			}
		}
	}
	
}


//Optimised approach, TC = O(2*(N*M)), SC = O(N) + O(M)
#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();

	//Use array instead of vector
	int rows[row] = {0};
	int cols[col] = {0};

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(matrix[i][j]==0){
				rows[i] = 1;
				cols[j] = 1;
			}
		}
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(rows[i]==1 || cols[j]==1){
				matrix[i][j] = 0;
			}
		}
	}
	
}

//Optimal approach, TC = O(2*N*M), SC = 0(1)
#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	int col0 = 1;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j] == 0){
				matrix[i][0] = 0;
				
				if(j!=0){
					matrix[0][j] = 0;
				}
				else{
					col0 = 0;
				}
			}
		}
	}

	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(matrix[i][j]!=0){
				if(matrix[0][j]==0 || matrix[i][0]==0 ){
					matrix[i][j]= 0;
				}
				
			}
		}
	}

	if(matrix[0][0]==0){
		for(int i=0; i<m; i++){
			matrix[0][i]=0;
		}
	}

	if(col0==0){
		for(int i=0; i<n; i++){
			matrix[i][0] = 0;
		}
	}
}




















