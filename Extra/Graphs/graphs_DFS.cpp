#include<iostream>
using namespace std;


int adj[5][5];
int vis[5];



void dfs(int n){
	vis[n] = 1;
	cout<<n<<" ";
	
	for(int i =0;i<5;i++){
		if(adj[n][i] == 1){
			if(vis[i] != 1){
				dfs(i);
			}
		}
	}
}

int main(){
	int e,x,y;
	cout<<"Enter the Edges : ";
	cin>>e;
	
	for(int i =0;i<5;i++){
		for(int j =0;j<5;j++){
		     adj[i][j];
		}
		vis[i] = 0;
	}
	
	
	for(int i =0;i<e;i++){
		cout<<"Enter x and y  : ";
		cin>>x>>y;
		adj[x][y] = 1;
		adj[y][x] = 1;
		
	}
	
	
	for(int i =0;i<5;i++){
		for(int j =0;j<5;j++){
		     cout<<adj[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	int st;
	cout<<"Enter start Vertix : ";
	cin>>st;
	
	dfs(st);
	
	
	
	
}
