#include<iostream>

using namespace std;


class AVL{
	private:
	struct node{
	int data;
	node * left;
	node * right;
}; 

	public:
		node * root;
		
		AVL(){
			root = NULL;
		}
		
		
		
		node * RR(node * rt){
			node * temp = new node;
			temp = rt->left;
			rt->left = temp->right;
			temp->right = rt;
			return temp; 
		}	
		
		node * LR(node * rt){
			node * temp = new node;
			temp = rt->right;
			rt->right = temp->left;
			temp->left = rt;
			return temp; 
		}	
		
		node * min(node * rt){
			while(rt->left!=NULL){
				rt = rt->left;
			}
			return rt;
		}
		
		node * max(node * rt){
			while(rt->right!=NULL){
				rt = rt->right;
			}
			return rt;
		}
		
		
		int height(node * rt){
			if(rt == NULL){
				return 0;
			}
			
			int Right = height(rt->left);
			int Left = height(rt->right);
			if(Right > Left){
				return Right+1;
			}else{
				return Left+1;
			}
			
		}
		
		int BalanceFactor(node * rt){
			return height(rt->left) - height(rt->right); 
		}
		
		void Inorder_traverse(node * rt){
			if(rt == NULL){
				return;
			}
			
			Inorder_traverse(rt->left);
			cout<<rt->data<<" , ";
			Inorder_traverse(rt->right);
			
			
		}
		
		
		void Insert(node *& rt , int n){
			if(rt == NULL){
				rt = new node;
				rt->data = n;
				rt->left = NULL;
				rt->right = NULL;
				return;
			}
			
			if(rt->data < n){
				Insert(rt->right , n);
			}
			if(rt->data > n){
				Insert(rt->left , n);
			}
			
			if(BalanceFactor(rt) == 2){
				if(min(rt)->data == n){
					rt = RR(rt);
				}else{
					rt = LR(rt->left);
					rt = RR(rt);
				}
			}else if(BalanceFactor(rt) == -2){
				if(max(rt)->data == n){
					rt = LR(rt);
				}else{
					rt = RR(rt->right);
					rt = LR(rt);
				}
			}
			
		}
		
		
		
		
		node * Search(node * rt,int data){
			if(rt == NULL){
				
				return rt;
			}
			if(rt->data == data){
				
				return rt;
			}
			
			if(data > rt->data){
				return Search(rt->right, data);
			}
			
			if(data < rt->data){
				return Search(rt->left, data);
			}
		}
		
		
		

		node * getSuccessor(node * rt  ,int value){
			if(rt== NULL){
				return rt;
			}
			node * t = new node;
			t = Search(rt, value);
			if(t->right != NULL){
				t = min(t->right);
				return t;
			}
			if(t->right == NULL){
				node * p = new node;
				node * rt = new node;
				rt = root;
				p = NULL;
				
				while(rt != t){
					if(rt->data > t->data){
						p = rt;
						rt = rt->left;
					}else{
						rt = rt->right;
					}
				}
				return p;
			}
			
		}
		
		node * RemoveItem(node * rt , int value){

			if(rt->data < value ){
				rt->right = RemoveItem(rt->right , value);
			}else if(rt->data > value ){
				rt->left = RemoveItem(rt->left , value);
			}
			else{
			
				if(rt->left == NULL && rt->right == NULL){
					delete rt;
					rt = NULL;
					return rt;
				}
				
				if(rt->left != NULL && rt->right == NULL){
					node * temp = new node;
					temp = rt;
					rt = rt->left;
					delete temp;
					
				}
				if(rt->left == NULL && rt->right != NULL){
					node * temp = new node;
					temp = rt;
					rt = rt->right;
					delete temp;
				
				}
				
				if(rt->left != NULL && rt->right != NULL){
					node * temp = new node;
					temp = getSuccessor(rt , value);
					rt->data = temp->data;
					rt->right = RemoveItem(rt->right , temp->data);
					
				}
				if(BalanceFactor(rt) == 2){
					if(rt->right == NULL){
						rt = RR(rt);
					}else{
						rt =LR(rt->left);
						rt =RR(rt);
					}
				}else if(BalanceFactor(rt) == -2){
					if(rt->left == NULL){
						rt =LR(rt);
					}else{
						rt = RR(rt->right);
						rt = LR(rt);
					}
				}
				return rt;
			}
		}	
};


int main(){

	AVL avl;
	avl.Insert(avl.root,1);
	avl.Insert(avl.root, 2);
	avl.Insert(avl.root, 3);
	avl.Insert(avl.root, 4);
	avl.Insert(avl.root, 5);
	

	cout<<endl;
	avl.Inorder_traverse(avl.root);
	

	avl.root = avl.RemoveItem(avl.root , 3);
	
	cout<<endl;
	avl.Inorder_traverse(avl.root);


	avl.root = avl.RemoveItem(avl.root , 1);
	
	cout<<endl;
	avl.Inorder_traverse(avl.root);

	avl.root = avl.RemoveItem(avl.root , 2);
	
	cout<<endl;
	avl.Inorder_traverse(avl.root);

	avl.root = avl.RemoveItem(avl.root , 4);
	cout<<endl;
	avl.Inorder_traverse(avl.root);
	
	avl.root = avl.RemoveItem(avl.root , 5);
	cout<<endl;
	avl.Inorder_traverse(avl.root);
	


}
