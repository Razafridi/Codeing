#include<iostream>
using namespace std;

struct Node{
	int info;
	Node * link;
	};

class Stack{
private:
	Node * top;
public:
	Stack(){
		top = NULL;
	}
	
	void push(int n){
		if(top == NULL){
			top = new Node;
			top->info = n;
			top->link = NULL;
			return;
		}
		
		Node * temp = new Node;
		temp->info = n;
		temp->link = top;
		top = temp;
		return;
	}
	
	int pop(){
		if(top == NULL){
			cout<<"Stack Underflow\n";
			return -1;
		}
		Node * temp = new Node;
		temp= top;
		int r = temp->info;
		top = top->link;
		delete temp;
		temp = NULL;
		return r;
		
	}

};

int main(){
	Stack s;
	s.push(23);
	s.push(423);
	s.push(90);
	s.push(100);
	
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	
}
