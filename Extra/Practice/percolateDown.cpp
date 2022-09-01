#include<iostream>
using namespace std;




int main(){

int arr[8] ={0,23,54,21,78,9,32,44};

int size = 7;
for(int j =0;j<2;j++){

for(int i =(size/2);i>0;i--){
    if(arr[i] < arr[2*i+1]){
		int t = arr[i];
		arr[i] = arr[2*i+1];
		arr[2*i+1] = t;
	}
	if(arr[i] < arr[2*i]){
		int t = arr[i];
		arr[i] = arr[2*i];
		arr[2*i] = t;
	}

}
}
for(int i=1;i<8;i++){
	cout<<arr[i]<<" ";
}

}
