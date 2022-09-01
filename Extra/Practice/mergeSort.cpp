#include<iostream>
using namespace std;


void mergeSort(int arr[] , int l ,int right){
	if(l<right){
		int mid = (l+right)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,right);
		
		merge(arr ,l,mid,right);

	}
}

void merge(int arr[] , int l,int m,int r){
	int s1 = m-l+1;
	int s2 = r-m;
	
	int a1[s1];
	int a2[s2];
	
	int i =0,j=0,k=0;
	for(int i=0;i<s1;i++){
		a1[i] = arr[k];
		k++;
	}
	for(int j=0;j<s2;j++){
		a1[j] = arr[k];
		k++;
	}
	
	i =0;
	j =0;
	k =0;
	
	while(i<s1 && j <s2){
		if(a1[i] > a2[j]){
			arr[k] = a2[j];
			k++;
			j++;
		}
		if(a1[i] < a2[j]){
			arr[k] = a1[i];
			k++;
			i++;
		}
	}
	
	while(i<s1){
			arr[k] = a1[i];
			k++;
			i++;
	}
	
		while(j<s2){
			arr[k] = a2[j];
			k++;
			j++;
	}
}

int main(){
int arr[10] = {23,66,22,99,1,43,66,135,9,2};
mergeSort(arr,0,10);


for(int i =0;i<10;i++){
	cout<<arr[i]<<" ";
}

}
