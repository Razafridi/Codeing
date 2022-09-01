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
		
		Tree(){
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
		
		
		int height(Node * r){
			if(r== NULL){
				return 0;
			}
			int R = height(r->left);
			int  L = height(r->right);
			
			if(R > L){
				return R+1;
			}else{
				return L+1;
			}
		}
		
		void Level_traverse(Node * r , int l , int c_l = 0){
			if(r == NULL){
				return;
			}
			if(l == c_l){
				cout<<r->info<<" ";			
			}
			
			Level_traverse(r->left , l , c_l+1);
			Level_traverse(r->right, l , c_l+1);
			
		}
		
};


int main(){
	Node * test = new Node;
	Tree t;
	t.insert(t.root , 23);
	t.insert(t.root , 12);
	t.insert(t.root , 26);
	t.insert(t.root , 25);
	t.insert(t.root , 27);
	t.insert(t.root , 24);
	t.insert(t.root , 28);
	t.Triversal(t.root);
	cout<<endl<<"Level order Traverse : \n";
	int  h = t.height(t.root);

	for(int i = 0; i<h+1;i++){
			t.Level_traverse(t.root,i);	
	}

}
