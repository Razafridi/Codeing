
#include<iostream>
using namespace std;

struct Node{
	int info;
	Node * left;
	Node * right;
};
//Work to do 
//finding successor
//deletion
class Tree{
	private:
		
	public:
		Node * root;
		int m1,m2,m3;
		
		Tree(){
			
			int m1 =300;
			int m2 = 300;
			int m3 = 300;
			root = NULL;
		}
		
		void insert(Node *&r,int data){
			if(r == NULL){
				r = new Node;
				r->info = data;
				r->left = NULL;
				r->right = NULL;
				return;
			}
			
			if(data > r->info){
				insert(r->right, data);
			}
			
			if(data < r->info){
				insert(r->left, data);
			}
		}
		
		Node * search(Node * r,int data){
			if(r == NULL){
				
				return r;
			}
			if(r->info == data){
				
				return r;
			}
			
			if(data > r->info){
				return search(r->right, data);
			}
			
			if(data < r->info){
				return search(r->left, data);
			}
		}
		
		void Triversal(Node * r){
			if(r == NULL){
				return;
			}
			Triversal(r->left);
			cout<<r->info<<" ";
			Triversal(r->right);
		
		}
		
		Node * Max(Node *r){
			while(r->right!=NULL){
				r = r->right;
			}
			
			return r;
		}
		
		Node * Min(Node *r){
			while(r->left!=NULL){
				r = r->left;
			}
			
			return r;
		}
		Node * successor(Node * r  ,int key){
			if(r== NULL){
				return r;
			}
			Node * temp = new Node;
			temp = search(r, key);
			if(temp->right != NULL){
				temp = Min(temp->right);
				return temp;
			}
			if(temp->right == NULL){
				Node * parent = new Node;
				Node * rt = new Node;
				rt = root;
				parent = NULL;
				
				while(rt != temp){
					if(rt->info > temp->info){
						parent = rt;
						rt = rt->left;
					}else{
						rt = rt->right;
					}
				}
				return parent;
			}
			
		}
		
		Node * Delete(Node * r , int key){

			if(r->info < key ){
				r->right = Delete(r->right , key);
			}else if(r->info > key ){
				r->left = Delete(r->left , key);
			}
			else{
				//Case I
				if(r->left == NULL && r->right == NULL){
					delete r;
					r = NULL;
					return r;
				}
				//Case II
				if(r->left != NULL && r->right == NULL){
					Node * temp = new Node;
					temp = r;
					r = r->left;
					delete temp;
					return r;
				}
				if(r->left == NULL && r->right != NULL){
					Node * temp = new Node;
					temp = r;
					r = r->right;
					delete temp;
					return r;
				}
				//Case II
				if(r->left != NULL && r->right != NULL){
					Node * temp = new Node;
					temp = successor(r , key);
					r->info = temp->info;
					r->right = Delete(r->right , temp->info);
					return r;
				}
			}
		}
		
		
void traverseMin(Node * r){
	if(r == NULL){
		return;
	}

	traverseMin(r->right);

   if(r->info < m1){
		m3 = m2;
		m2 = m1;
		m1 = r->info;
	}else if(r->info < m2){
		m3 = m2;
		m2 = r->info;
	}else if(r->info < m3){
		m3 = r->info;
	}
	
	cout<<m1<<" "<<m2<<" "<<m3<<" "<<endl;
		traverseMin(r->left);
}
};


int main(){
	Node * test = new Node;
	Tree t;
	t.insert(t.root , 102);
	t.insert(t.root , 4);
	t.insert(t.root , 5);
	t.insert(t.root , 43);
	t.insert(t.root , 76);
	t.insert(t.root , 0);
	t.insert(t.root , 32);
	t.Triversal(t.root);
	cout<<endl;
	t.traverseMin(t.root);


}
