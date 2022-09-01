#include<iostream>

using namespace std;

		struct Node{
			int ele;
			Node * next;
		};
class List{
	private:

	public:
		Node * head,* temp,* temp1;
		int length;
		List(){
			length = -1;
			head = NULL;
			temp = NULL;
			temp1 = NULL;
		}
		
		void push(int data){
			
			if(head == NULL){
				
				temp = new Node;
				temp->ele = data;
				temp->next = NULL;
				head = temp;
			

			}else{
			
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp1= NULL;
			temp1 = new Node;
			temp1->ele = data;
			temp->next  = temp1;
			temp1->next = NULL;}
			
			length++;
		}
		
		void insert(int data , int ele){
			if(head == NULL){
					return;
			}
				
				temp = head;
				while(temp->next != NULL){
					if(temp->ele == ele){
						temp1 = new Node;
						temp1->ele = data;
						temp1->next = temp->next;
						temp->next = temp1;
						return;
					}
					temp = temp->next;
				}
				cout<<"Number not found\n";
			}
			
			void remove(int data){
				if(head == NULL){
					return;
				}
				
				temp = head;
				while(temp->next != NULL){
					if(temp->next->ele == data){
						temp1 = new Node;
						temp1 = temp->next;
						temp->next = temp1->next;
						delete temp1;
						temp1=NULL;
						return;
					}
					temp = temp->next;
				}
			}
		
		
		void print(){
			temp = head;
			while(temp->next != NULL){
				cout<<temp->ele<<" ";
				temp = temp->next;
			}
			cout<<temp->ele<<" ";
		}
		int max(){
			temp = head;
			int m = temp->ele;
			while(temp != NULL){
				if(temp->ele > m){
					m = temp->ele;
				}
				temp = temp->next;
			}
			return m;
		}
		
		int min(){
			temp = head;
			int m = temp->ele;
			while(temp != NULL){
				if(temp->ele < m){
					m = temp->ele;
				}
				temp = temp->next;
			}
			return m;
		}
		
		void middleOfList(){
			 int l =0;
			 Node * temp = head;
			 while(temp!=NULL){
			 	temp = temp->next;
			 	l++;
			 }
			 int m = l/2;
			 temp = head;
			 int c =0;
			 while(temp!=NULL){
			 	if(c == m){
			 		cout<<temp->ele<<" ";
				 }
			 	temp = temp->next;
			 	c++;
			 }
		}
};


int main(){
	
	List list1;

	list1.push(78);
	list1.push(28);
	list1.push(11);
	list1.push(55);
	list1.push(99);

	list1.print();

	cout<<endl;
	list1.middleOfList();
	

	
}
