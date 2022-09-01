#include<iostream>

using namespace std;

class Stack{
	private:
		int top ;
		int size;
		int * arr;
	public:
		Stack(){
			top = -1;
			size = 100;
			arr = new int[size];
		}
		
		Stack(int n){
			top = -1;
			size = n;
			arr = new int[size];
		}
		void push(int n){
			if(top == size-1){
				cout<<"\nError : Stack Overflow \n ";
				return;
			}
			arr[++top] = n;
		}
		
		
		void pop(){
			if(isEmpty()){
				cout<<"\nError : Stack Underflow \n ";
				return;
			}
			top--;
		}
		
		int tos(){
			if(!isEmpty()){
				return arr[top];
			}else{
				cout<<"\n Error : Stack Underflow ";
				return -1;
			}
		} 
		
		bool isEmpty(){
			if(top== -1){
				return true;
			}else{
				return false;
			}
		}
		
		void print(){
			cout<<endl;
			for(int i =0;i<top+1;i++){
				cout<<" "<<arr[i];
			}
		}
};

int main(){
	
	Stack s;
	s.push(12);
	s.push(90);
	s.push(43);
	s.push(123);
	s.push(67);
	
	s.print();
	
	s.pop();
	
	s.print();
	
	cout<<s.tos()<<endl;
}
