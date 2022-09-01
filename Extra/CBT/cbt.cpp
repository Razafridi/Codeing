#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

struct Node{
	int info;
	Node * left;
	Node * right;

};



class Queue{
	private:
		struct node{
			Node * ele;
			node * link;
		};
	public:
		node *front , *back , *temp;
		Queue(){
			front = back = NULL;
		}
		
		void enqueue(Node * n){
			temp = new node;
			temp->ele = n;
			temp->link = NULL;
			if(front == NULL){
				front = temp;
				back = temp;
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
		
		Node * getFront(){
			if(front != NULL){
				return front->ele;
			}
			return 0;
		}
		
		void print(){
			cout<<endl;
			node * temp = front;
			while(temp!= NULL){
				cout<<temp->ele->info<<" ";
				temp=temp->link;
			}
			
			
		}
};



	
class CBT{
	private:
		Queue q;
		
	public:
		Node * root ;
		int arr[100];
		int i;

		CBT(){
			root = NULL;
			i = 0;
		}
	

		Node * createNode(int val){
			Node * r = new Node;
			r->info = val;
			r->left = NULL;
			r->right = NULL;
			return r;
		}
		
		void insert(Node *r , int val){
			if(root  == NULL){
				root = new Node;
				root->info = val;
				root->left = NULL;
				root->right = NULL;
				arr[i] = val;
				i++;
				q.enqueue(root);
				return;
				
			}
			
			Node * curr = q.getFront();
			
			
		
			if(curr->left == NULL){
				curr->left = new Node;
				curr->left->info = val;
				curr->left->left = NULL;
				curr->left->right = NULL;
				arr[i] = val;
				i++;
				q.enqueue(curr->left);
				return;
			}
			
			if(curr->right == NULL){
				curr->right = new Node;
				curr->right->info = val;
				curr->right->left = NULL;
				curr->right->right = NULL;
				arr[i] = val;
				i++;
				q.enqueue(curr->right);
				q.dequeue();
				return;
			}
			if(curr->left == NULL && curr->right == NULL){
				q.dequeue();
				
			}
			

		}
		
		void traverse(Node * r){
			if(r== NULL){
				return;
			}
			
			traverse(r->left);
			cout<<r->info<<" ";
			traverse(r->right);
		}
		
		void checkQueue(){
			q.print();
		}
		
		int height(Node * r){
			if(r == NULL){
				return 0;
			}
			
			int R = height(r->left);
			int L = height(r->right);
			
			if(R > L){
				return R+1;
			}else{
				return L+1;
			}
		}
		
	void PercolateDown(Node * n){
		if(n->left == NULL || n->right == NULL){
			return;
		}
		PercolateDown(n->left);
		PercolateDown(n->right);
		
		if(n->info < n->left->info ){
			int temp = n->info;
			n->info = n->left->info;
			n->left->info = temp;
			
		}
		if(n->info < n->right->info ){
			int temp = n->info;
			n->info = n->right->info;
			n->right->info = temp;
			
		}
		PercolateDown(n->left);
		PercolateDown(n->right);
		
	}
	
	void PercolateUp(Node * n){
		if(n->left == NULL || n->right == NULL){
			return;
		}
		PercolateUp(n->left);
		PercolateUp(n->right);
		
		if(n->info > n->left->info ){
			int temp = n->info;
			n->info = n->left->info;
			n->left->info = temp;
			
		}
		if(n->info > n->right->info ){
			int temp = n->info;
			n->info = n->right->info;
			n->right->info = temp;
			
		}
		PercolateUp(n->left);
		PercolateUp(n->right);
		
	}
};

int main(){
	
	CBT t;
	
	t.insert(t.root,23);
	t.checkQueue();
	t.insert(t.root,24);
	t.checkQueue();
	t.insert(t.root,89);
	t.checkQueue();
	t.insert(t.root,100);
	t.checkQueue();	
	t.insert(t.root,200);
	t.checkQueue();	
	t.insert(t.root,4);
	t.checkQueue();	
	t.insert(t.root,89);
	t.checkQueue();	
	t.insert(t.root,34);
	t.checkQueue();	
	t.insert(t.root,12);
	t.checkQueue();	

	cout<<endl;
	t.traverse(t.root);
	cout<<endl;
	cout<<t.height(t.root);
	
	cout<<endl;
	t.PercolateDown(t.root);
	cout<<endl;
	t.traverse(t.root);
	cout<<endl;
	cout<<endl;
	t.PercolateUp(t.root);
	cout<<endl;
	t.traverse(t.root);
	cout<<endl;
	
	
	
}
