//Problem statement - given a 2D matrix of size N*M, rotate the elements of matrix clockwise only once
#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    
    int tl = 0;
    int bl = 0;
    int tr = m-1;
    int br = n-1;

    while(tl<tr && bl<br){
        int temp = mat[tl][bl];

        for(int i=tl+1; i<=br; i++){
            mat[i-1][bl] = mat[i][bl];
        }

        for(int i = bl+1; i<=tr; i++){
            mat[br][i-1] = mat[br][i];
        }

        for(int i = br-1; i>=tl; i--){
            mat[i+1][tr] = mat[i][tr];
        }

        for(int i = tr-1; i>=bl; i--){
            mat[tl][i+1] = mat[tl][i];
        }
        mat[tl][bl+1] = temp;
        tl++;
        bl++;
        tr--;
        br--;
    }

}
