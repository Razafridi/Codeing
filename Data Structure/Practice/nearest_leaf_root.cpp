#include<iostream>
using namespace std;

struct Node{
	int info;
	Node * left;
	Node * right;
};
int h = 2;
int val = 0;
void traverse(Node * root,int lh =0){
	if(root==NULL){
		return;
	}
	traverse(root->left,lh+1);
	traverse(root->right,lh+1);
	if(root->left == NULL && root->right == NULL){
		if(lh < h){
			h = lh;
			val = root->info;
		}
	}

}

int main(){
	Node * root = new Node{78};
	root->left = new Node{99};
	root->right = new Node{28};
	root->right->right = new Node{11};
	root->right->left = new Node{55};
	
	
	traverse(root);
	cout<<val;
}
