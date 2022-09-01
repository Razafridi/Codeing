#include<iostream>
using namespace std;

class List{
	private:
		struct Node{
			int ele;
			Node * next;
		};
	
	public:
		Node *head, *temp , *temp1;
		
		List(){
			head = NULL;
			temp = NULL;
			temp1 = NULL;
		}
		void insert(){
			if(head == NULL){
				cout<<"Enter Value  : ";
				head = new Node;
				cin>>head->ele;
				head->next = head;
				temp = head;
				return;
			}
			temp = head;
			int key;
			cout<<"Enter key : ";
			cin>>key;
			
			do{
				if(temp->ele == key){
					temp1 = new Node;
					cout<<"Enter a Value : ";
					cin>>temp1->ele;
					temp1->next = temp->next;
					temp->next = temp1;
				}
				
				temp = temp->next;
			}while(temp!=head);
		}
		
		void remove(){
			if(head== NULL){
			cout<<"\nList Empty.\n";
			return;
			}
			temp = head;
			int key;
			cout<<"Enter key: ";
			cin>>key;
			do{
				if(temp->next->ele == key){
					temp1 = temp->next;
					temp->next = temp1->next;
					delete temp1;
					temp1 = NULL;
					return;
				}
				temp = temp->next;
			}while(temp->next!=head);
			
			if(head->ele ==key ){
				temp1 = head;
				head = head->next;
				temp->next = head;
				delete temp1;
				temp1 = NULL;
				return;
			}
		}
		
		void print(){
			temp = head;
			do{
				cout<<" "<<temp->ele<<" ";
				temp = temp->next;
			}while(temp!=head);
		}
		void print(int n){
			temp = head;
			for(int i =0;i<n;i++){
				cout<<temp->ele<<endl;
				temp = temp->next;
			}
		}
};

int main(){
	List l;
	l.insert();
	l.insert();
	l.insert();
	l.insert();
	l.print();
	l.remove();
	l.remove();
	l.print();
	cout<<endl;
	l.print(10);
	
}
