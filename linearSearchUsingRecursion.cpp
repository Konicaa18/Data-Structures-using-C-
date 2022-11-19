//recursive function for linear search on an array of integers
#include<iostream>
using namespace std;

int linearSearch(int* arr,int n, int x){
	if (n==0){
		return -1;
	}
	if (arr[n]==x){
		return n;
	}
	return linearSearch(arr,n-1,x);
}

int main(){
	int arr[4]={1,2,3,4};
	cout<<linearSearch(arr,4,8);
	return 0;
}
