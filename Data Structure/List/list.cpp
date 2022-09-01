#include<iostream>
using namespace std;

class List{
	private:
		int *p,*q;
		int len;
	public:
		List(){
			p = new int;
			q = new int;
			len = -1;
			q = p;
		}
		bool isEmpty(){
			if(p==q){
				return true;
			}
			return false;
		}
		
		void push(int n){
			*p = n;
			p=p+1;
			len++;
		}
		
		void pop(){
			if(!isEmpty()){
				p--;
				len--;
			}
		}
		int search(int n){
			if(!isEmpty()){
				for(int i=0;i<=len;i++){
					if(*(q+i) == n){
						return i;
					}
				}
				cout<<"Item not found ..\n ";
				
			}
		}
		
		void replace(int i, int num){
			p =q;
			*(p+i) = num;
			p = p+len+1;
		}
		
		
		void print(){
			for(int i =0; i<=len;i++){
				cout<<*(q+i)<<" , ";
			}
			cout<<endl;
		}
		void insertAt(int pos,int n){
			if(pos > len){
				cout<<"Out of Bound";
			}else{
				int i = len;
				p++;
				while(i!=pos){
					*(p)= *(p-1);
					i--;
					p=p-1;
				}
				*p = n;
				p = q;
				p = p+len+1;
			}
		}
};

int main(){
	List list;
	list.push(90);
	list.push(700);
	list.push(123);
	list.push(121);
	list.print();
	list.replace(1,800);
	list.print();
	list.push(9000);
	list.push(786);
	list.push(123);
	list.print();

	list.insertAt(3,6000);
	list.print();
	cout<<list.search(9000);
	
}
