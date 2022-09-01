#include<iostream>
using namespace std;

class Queue{
	private:
		struct Node{
			int ele;
			Node * link;
		};
	public:
		Node *front , *back , *temp;
		Queue(){
			front = back = NULL;
		}
		
		void enqueue(int n){
			temp = new Node;
			temp->ele = n;
			temp->link = NULL;
			if(front == NULL){
				front = back = temp;
			}else{
				back->link = temp;
				back = temp;
			}
		}
		
		void dequeue(){
			if(isEmpty()){
				cout<<"Queue is empty .. \n";
			}else{
				temp = front;
				front = front->link;
				delete temp;
				temp = NULL;
			}
		}
		
		bool isEmpty(){
			if(front == back){
				return true;
			}else{
				return false;
			}
		}
		
		void print(){
			temp = front;
			do{
				cout<<temp->ele<<" ";
				temp = temp->link;
			}while(temp!=NULL);
		
		}
};
int main(){
	Queue q;
	q.enqueue(34);
	q.enqueue(90);
	q.enqueue(76);
	q.print();
	q.dequeue();
	cout<<"\n";
	q.print();
	q.dequeue();
	cout<<"\n";
	q.print();
	
}
