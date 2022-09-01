#include<iostream>
#include<queue>
using namespace std;



int main(){
	
	int v = 8;
	
	
	
	int adj[v][v];
	int vis[v];
	
	int path[7];



	int e,x,y;
	cout<<"Enter the Edges : ";
	cin>>e;
	
	for(int i =0;i<v;i++){
		for(int j =0;j<v;j++){
		     adj[i][j] = 0 ;
		}
		vis[i] = 0;
	}
	
	
	for(int i =0;i<e;i++){
		cout<<"Enter x and y  : ";
		cin>>x>>y;
		adj[x][y] = 1;
		adj[y][x] = 1;
		
	}
	
	
	for(int i =0;i<v;i++){
		for(int j =0;j<v;j++){
		     cout<<adj[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	int st;

	
	cout<<"Enter start Vertix : ";
	cin>>st;
		int in = 0;
	queue<int> q;
	q.push(st);
	vis[st] = 1;
	while(!q.empty()){
		int f = q.front();
		cout<<f<<" ";
		path[in] = f;
		q.pop();
		for(int i =0;i<v;i++){
			if(adj[f][i] == 1){
				if(vis[i] != 1){
					q.push(i);
					vis[i] = 1;
				}
			}
		}
	}
	
	//my algo
	int start,end,curr;
	cout<<"Enter start v : ";
	cin>>start;
	cout<<"Enter End v : ";
	cin>>end;
	curr = end;
	cout<<"\n";
	for(int i =0;i<v;i++){
		if(adj[curr][i] == 1){
			for(int j =0;j<curr;j++){
				if(curr == path[j]){
					curr = j;
					cout<<j<<" ";
					break;
				}
			}
		}
	}
	
	
	
	
	
}
