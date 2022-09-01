#include<iostream>
using namespace std;

void series(int a ,int b,int c,int n){
	if(n == 0){
		return;
	}
	cout<<a<<" ";
	series(b,c,a+b+c,n-1);
}

int main(){
	series(3,6,9,6);
}
