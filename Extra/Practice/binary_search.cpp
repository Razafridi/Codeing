#include<iostream>
using namespace std;

int BinarySearch(int arr[], int size, int val ){
	int m =0;
	int l = 0;
	int r = size-1;
	for(int i =0;i<size;i++){
		m = (l+r)/2;
		if(arr[m] == val){
			return m;
		}
		
		if(arr[m] > val){
			l = m+1;
		}
		if(arr[m] < val ){
			r = m-1;
		}
		if(l == r){
			return -1;
		}
	}
}

int main(){
	
	int  arr[10] = {12,32,33,65,66,78,87,89,90,100};
	cout<<"Value at index : "<<BinarySearch(arr,10,66);
	
}
