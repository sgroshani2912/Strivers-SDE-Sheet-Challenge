//Problem statement Implement pow(x, n).

//Brute force approach, TC = O(N), SC = O(1)
#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	long long int ans = 1;
	for(int i=1; i<=n; i++){
		ans = (ans*x)%m;
	}
	return  ans % m;
}

//Optimal approach, TC = O(log(N)), SC = O(1)
#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	long long int ans = 1;
	long long int a = x;
	while(n>0){
		if(n%2==0){
			a = (a*a)%m;
			n = n/2;
		}
		else{
			ans = (ans*a)%m;
			n = n-1;
		}
	}
	return ans%m;
}
