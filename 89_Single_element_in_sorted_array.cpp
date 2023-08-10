// http://rb.gy/gxozo

//Binary search approach

int singleNonDuplicate(vector<int>& arr)
{
	int low = 0;
	int high = arr.size() - 1;

	while(low<=high){
		int mid = (low+high)>>1;
		if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]) return arr[mid];

		else if(mid%2 != 0 && arr[mid-1] != arr[mid] || mid%2==0 && arr[mid+1] != arr[mid]) high = mid-1;
		
		else{
			low = mid+1;
		}
	}
	return -1;
}

//Xor approach

int singleNonDuplicate(vector<int>& arr)
{
	int x = 0;
	for(auto i: arr){
		x ^= i;
	}
	return x;
}
