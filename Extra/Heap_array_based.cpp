#include<iostream>
#include<math.h>
using namespace std;

	
class Heap{
	private:
		
	public:
		int arr[8];
		int i ;
		
		Heap(){
			int ar1[8]= {0,34,65,98,67,3,57,22};
			for(int i =0;i<8;i++){
				arr[i] = ar1[i];
			}
			i = 1;
		}
		
		void percolateDown(int ind){
			if(arr[ind] < arr[2*ind]){
				int tmp = arr[ind];
				arr[ind] =  arr[2*ind];
				arr[2*ind] = tmp;
			}
			if(arr[ind] < arr[2*ind+1]){
				int tmp = arr[ind];
				arr[ind] =  arr[2*ind+1];
				arr[2*ind+1] = tmp;
			}
		}
		
		void traverse(){
			for(int i =1;i<8;i++){
				cout<<arr[i]<<" ";
			}
		}

		
	
		
};

int main(){
	
	Heap h;
	h.traverse();
	for(int i = 7/2;i>0;i--){
	h.percolateDown(i);
	cout<<endl;
	h.traverse();
}
cout<<endl<<endl;
	for(int i = 7/2;i>0;i--){
	h.percolateDown(i);
	cout<<endl;
	h.traverse();
}
	cout<<endl;
	h.traverse();
}
