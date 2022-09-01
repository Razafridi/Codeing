#include<iostream>
using namespace std;

int main(){
	
	int r , c;
	cout<<"Enter no. of R and C : ";
	cin>>r>>c;
	int arr[r][c];
	for(int i =0;i<r;i++){
		for(int j =0;j<c;j++){
			cout<<"Enter value for Row "<<i<<" and Column "<<j<<" : ";
			cin>>arr[i][j];
		}
	}
	
	
	for(int i =0;i<r;i++){
		for(int j =0;j<c;j++){
			if(arr[i][j] == 0){
				continue;
			}
			else if(arr[i][j] == 1){
				break;
			}else if(i == 0){
				
				for(int k =0;k<r;k++){
					
					arr[i][k] = arr[i][k]/arr[0][j];
				}
			}
		}
	}
	
	
	for(int i =0;i<r;i++){
		for(int j =0;j<c;j++){
		
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	
}
