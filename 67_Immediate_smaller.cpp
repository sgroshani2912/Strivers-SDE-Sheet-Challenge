// https://www.codingninjas.com/studio/problems/immediate-smaller-element-_1062597?leftPanelTab=1
void immediateSmaller(vector<int>& a)
{
	int n = a.size();
	for(int i=0; i<n-1; i++){
		if(a[i]>a[i+1]){
			a[i] = a[i+1];
		}
		else{
			a[i] = -1;
		}
	}
	a[n-1] = -1;
	return;
}
