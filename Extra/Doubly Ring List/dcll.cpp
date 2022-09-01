#include<iostream>
using namespace std;



class List{
	private:
		struct Node{
			int ele;
			Node * next;
			Node * pre;
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
				head = new Node;
				cout<<"Enter a Value : ";
				cin>>head->ele;
				head->next = head;
				head->pre = head;
				temp = head;
				return;
			}
			temp = head;
			int key;
			cout<<"Enter Key For Insertion : ";
			cin>>key;
			
			do{
				if(temp->ele == key){
					temp1 = new Node;
					cout<<"Enter Value : ";
					cin>>temp1->ele;				
					temp1->next = temp->next;
					temp1->pre = temp;
					temp->next->pre = temp1;
					temp->next = temp1;
					
					return;
					
					}
				
				temp = temp->next;
			}while(temp!=head);
			
		}
		
		void remove(){
			if(head == NULL){
				cout<<"\nList Empty.\n";
				return;
			}
			temp = head;
			int key;
			cout<<"Enter Key to Remove : ";
			cin>>key;
			if(head->next == head && head->ele == key){
				delete head;
				head= NULL;
				return;
			}
			if(head->ele == key && head->next != head){
				Node * t = new Node;
				t = head;
				head->pre->next = head->next;
				head->next->pre = head->pre;
				head = head->next;
				delete t;
				return;
			}
			do{
				if(temp->ele == key){
					
					temp->pre->next = temp->next;
					temp->next->pre = temp->pre;
					
					delete temp;
					temp = NULL;
					return;
						}
			temp = temp->next;
			}while(temp!=head);
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
	l.insert();
	l.insert();
	l.print();
	


	
	
	
	
}
