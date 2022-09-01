#include<iostream>
using namespace std;

class Hash{
	private:
		int * arr,*arr1;
		int size , tot;
	public:
		Hash(int s){
			arr = new int[s];
			for(int i =0; i<s;i++){
				arr[i] = -1;
			}
			size  =s; 
			tot = 0;
		}
		
		void traverse(){
			for(int i =0; i<size;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		void rehashing(){
			 int nsize = 2*size;
			 arr1 = new int[nsize];	
			 for(int i =0;i<nsize;i++){
			 	arr1[i] = -1;
			 }
			 
			 for(int i=0;i<size;i++){
			 	int ind = arr[i]%nsize;
			 	while(arr1[ind] != -1){
			 		ind++;
			 		if(ind >=nsize){
			 			ind =0;
					 }
				 }
				 arr1[ind] = arr[i];
			 }
			 
			 size = nsize;
			 arr = new int[size];
			 for(int i=0;i<size;i++){
 		         arr[i] = arr1[i];
			 }
		}
		
		void insert(int val){
			if(tot == size-2){
				rehashing();
				cout<<"Rehashing..."<<endl;
				return;
			}
			if(val%size == -1){
				arr[val%size] = val;
				tot++;
			}
			if(val%size != -1 ){
				int i = val%size;
				while(arr[i] != -1){
					i++;
					if(i >=size){
						i = 0;
					}
				}
				arr[i] = val;
				tot++;
			}
			traverse();
		}
};

int main(){
	
	Hash h(10);

	h.traverse();
	h.insert(45);
	h.insert(100);
	h.insert(23);

	h.insert(26);
	h.insert(79);
	h.insert(10);
	h.insert(43);
	h.insert(10);

	h.insert(43);
	
	h.insert(10);
	h.insert(43);
	
	h.insert(45);
	h.insert(45);
	h.insert(100);
	h.insert(23);

	h.insert(26);
	h.insert(79);
	h.insert(10);
	h.insert(43);
		h.insert(100);
	h.insert(23);

	h.insert(26);
	h.insert(79);
	h.insert(10);
	h.insert(43);
	h.insert(10);

	h.insert(43);
	
	h.insert(10);
	h.insert(43);
	
	h.insert(45);
	h.insert(45);
	h.insert(100);
	h.insert(23);

	h.insert(26);
	h.insert(79);
	h.insert(10);
	h.insert(43);


}
