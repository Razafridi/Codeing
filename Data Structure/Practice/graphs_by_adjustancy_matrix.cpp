#include<iostream>
#include<queue>
using namespace std;

int main(){
	
	int v,e;
	cout<<"Enter the number of vertexes : ";
	cin>>v;
	cout<<"Enter the number of edges : ";
	cin>>e;
	
	queue<int> q[v];
	
	for(int i =0;i<e;i++){
		int x,y;
		cout<<"Enter x and y : ";
		cin>>x>>y;
		q[x].push(y);
		q[y].push(x);
		
	}
	
//	for(int i =0;i<v;i++){
//		cout<<i<<" connect with : ";
//		while(!q[i].empty()){
//			cout<<q[i].front()<<" ";
//			q[i].pop();
//		}
//		cout<<endl;
//		
//	}
int vis[v] ={0};
queue<int> tr;
cout<<"Enter starting point : ";
int st;
cin>>st;
tr.push(st);
while(!tr.empty()){
	int f = tr.front();
	cout<<f<<" ";
	tr.pop();
	while(!q[f].empty()){
		int front = q[f].front();
		q[f].pop();
		if(vis[front] != 1){
			tr.push(front);
			vis[front] = 1;
		}
	}
}
	
}
