#include<iostream>
#include<queue>
using namespace std;

int main(){
	int arr[5][5];
	int vis[5];
	
	for(int i =0;i<5;i++){
        for(int j =0;j<5;j++){
				arr[i][j] = 0;
		}
	vis[i] = 0;
	}
	for(int i =0;i<7;i++){
		int x,y;
		int w;
		cin>>x>>y;
		cin>>w;
		arr[x][y] = w;
		arr[y][x] = w;
	}
	
	
		for(int i =0;i<5;i++){
        for(int j =0;j<5;j++){
				cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	int st;
	queue<int> q;
	cin>>st;
	q.push(st);
	while(!q.empty()){
		int f = q.front();
		int min = 100;
		int ind = -1;
		for(int i=0;i<5;i++){
			if(vis[i] != 1){
				if(arr[f][i] < min){
					min = arr[f][i];
					ind = i;
				}
			}
		}
		vis[ind] = 0;
		q.push(ind);
		cout<<min<<" ";
		
	}
	
}
