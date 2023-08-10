// https://rb.gy/4r2py

#include <bits/stdc++.h>

int pivot_index(int* arr, int n){
    
    int l = 0;
    int h = n-1;
    while(l<h){
        int m = (l+h)>>1;
        if(arr[m]>=arr[0]) {
            l=m+1;
        }
        else{
            h=m;
        }
    }
    return l;
}

int bs(int* arr, int l, int h, int key){
    while(l<=h){
        int m = (l+h)>>1;
        if(arr[m]==key) return m;
        else if(key>arr[m]) l = m+1;
        else h = m-1;
    }
    return -1;
}

int search(int* arr, int n, int key) {
    int pivot = pivot_index(arr, n);

    if(key<= arr[n-1] && key>=arr[pivot]){
        return bs(arr, pivot, n-1, key);
    }
    return bs(arr, 0, pivot-1, key);
}
