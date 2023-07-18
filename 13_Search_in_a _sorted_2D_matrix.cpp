//Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.
//Given matrix has the following properties:
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row
//M -> no of rows
//N -> no of columns

//Brute force approach, TC = O(M*N), SC = O(1)
bool searchMatrix(vector<vector<int>>& mat, int target) {
      for(int i=0; i<mat.size(); i++){
          for(int j=0; j<mat[0].size(); j++){
              if(mat[i][j]== target){
                  return true;
              }
          }
      }
      return false;
}

//Binary search approach, TC = O(log(M*N)), SC = O(1)
bool searchMatrix(vector<vector<int>>& mat, int target) {

    int m = mat.size();
    int n = mat[0].size();

    int low = 0;
    int high = (m*n)-1;
    while(low<=high){
        int mid = (low + (high - low) / 2);
        if(mat[mid/n][mid%n] == target){
            return true;
        }
        else if(mat[mid/n][mid%n] < target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return false;
}
