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
		Node *head ,*temp,*temp1;
		List(){
			head = temp = temp1 = NULL;
		}
		
		void push(int data){
			if(head == NULL){
				head = new Node;
				head->ele = data;
				head->next = NULL;
				head->pre = NULL;
				temp = head;
				return;
			}
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp1 = new Node;
			
			temp1->ele = data;
			temp1->next = temp->next;
			temp1->pre = temp;
			temp->next = temp1;
			
		}
		
		void insert(int data , int after){
			if(head == NULL){
				head = new Node;
				head->ele = data;
				head->pre = NULL;
				head->next = NULL;
				return;
			}

			temp = head;
			while(temp != NULL){
				if(temp->ele == after ){
					temp1 = new Node;
					temp1->ele = data;
					temp1->pre = temp;
					temp1->next = temp->next;
					if(temp->next != NULL){
						temp->next->pre = temp1;
					}
					temp->next = temp1;
					return;
					
				}
				temp = temp->next;
			}

	}
	
	void remove(int data){
		if(head == NULL){
			cout<<"List is empty\n";
			return;
		}
		temp = head;
//		if(head->ele == data && head->next == NULL){
//			delete head;
//			head = NULL;
//			return;
//		}
//		if(head->ele == data && head->next != NULL){
//			temp1 = new Node;
//			temp1 = head;
//			head = head->next;
//			delete temp1;
//			temp1 = NULL;
//			return;
//		}
		while(temp->next != NULL){
			if(temp->ele == data && temp->pre != NULL && temp->next !=NULL){
				temp1 = new Node;
				temp->pre->next = temp->next;
				temp->next->pre = temp->pre;
				temp1 = temp;
				temp = temp->next;
				delete temp1;
				temp1 = NULL;
				return;
			}
			if(temp->ele == data && temp->pre == NULL){
				temp1 = new Node;
				temp1 = head;
				head = head->next;
				delete temp1;
				temp1 = NULL;
				return;
			}
		temp = temp->next;
		}
		if(temp->ele == data){
			temp1 = new Node;
			temp1 = temp;
			temp->pre->next = NULL;
			temp = temp->pre;
			delete temp1;
			temp1 = NULL;
			
		}
	}
		
		void print(){
			temp = head;
			while(temp->next !=NULL){
				cout<<temp->ele<<endl;
				temp = temp->next;
			}
			cout<<temp->ele<<endl;
		}
};


int main(){
	
	List list;
	list.insert(23,0);
	list.insert(45,23);
	list.insert(34,23);
	list.print();
	list.remove(45);
	list.print();

	
}
