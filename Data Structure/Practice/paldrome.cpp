#include<iostream>
using namespace std;

bool paldrome(string arr , int size){
	int l = size-1;
	for(int i =0;i<size/2;i++){
		if(arr[i] != arr[l]){
			return false;
		}
		l--;
	}
	return true;
}

int main(){

cout<<paldrome("opps",4);

}
