#include<iostream>
#include<stack>
using namespace std;

int main(){
	
	char arr[5][5] =
	 {{'#','.','#','.','#'},
	  {'#','#','.','.','.'},
	  {'.','.','.','#','.'},
	  {'.','#','#','.','.'},
	  {'.','#','#','.','#'},
	};
	int vis[5][5] = {0};
	
	for(int i =0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	stack<int> stx;
	stack<int> sty;
	int sx,sy;
	int i,j; // stack rec
	cout<<"Enter start point : ";
	cin>>sx>>sy;
	stx.push(sx);
	sty.push(sy);
	while(!stx.empty()){
		i = stx.top();
		j = sty.top();
		cout<<"("<<i<<" , "<<j<<"), ";

		for(int c =0;c<5;c++){
		
		if( i < 5 && arr[i+1][j] == '.'){
				stx.push(i+1);
				sty.push(j);
				arr[i+1][j] = '#';
	}else if( i >= 0 && arr[i-11][j] == '.'){
			stx.push(i-1);
			sty.push(j);
			arr[i-1][j] = '#';
		}else if( j  < 5 && arr[i][j+1] == '.'){
				stx.push(i);
				sty.push(j+1);
				arr[i][j+1] = '#';
		}else if( j >= 0 && arr[i][j-1] == '.'){
			stx.push(i);
			sty.push(j-1);
			arr[i][j-1] = '#';
		}else{				i = stx.top();
							j = sty.top();
					stx.pop();
					sty.pop();
		}
	}
	cout<<endl;
		for(int i =0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	} 
	
}
