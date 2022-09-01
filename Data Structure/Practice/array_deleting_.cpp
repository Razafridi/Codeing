#include<iostream>
using namespace std;



void deleteVal(int * &a , int val , int size){
	int * q = new int;
	bool flag = false;
	for(int i =0;i<size-1;i++){
		if(*(a+i) == val){
			flag = true;
		}
		
		if(flag == true){
			*(a+i) = *(a+i+1);
		}
	}
	if(!flag){
		if(*(a+size-1) == val)
		a--;
	}else{
		a--;
	}
}


int main(){
	int * a = new int;
	int * p = a;
	int * q;
	*a= 67;
	a++;
	*a = 90;
	a++;
	*a = 45;
	deleteVal(a , 90,3);
	
	cout<<*a<<" ";
	cout<<*(a-1)<<" ";
	}
