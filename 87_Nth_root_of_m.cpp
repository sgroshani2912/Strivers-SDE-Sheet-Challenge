// https://rb.gy/6xyem

long long power(int mid, int n, int m){
  long long ans = 1;
  for(int i=0; i<n; i++){
    ans*=mid;
    //Avoid overflow of number
    if(ans>m) return -1;
  }
  if(ans == m) return 1;
  return 0;
}

int NthRoot(int n, int m) {
  int high = m; 
  int low = 1;
  while(high>=low){
    int mid = low + (high-low)/2;
    int num = power(mid, n, m);
    if(num == 1){
      return mid;
    }
    else if(num == -1){
      high = mid-1;
    }
    else{
      low = mid+1;
    }
  }
  return -1;
}
