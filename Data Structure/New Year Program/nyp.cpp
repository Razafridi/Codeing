#include<iostream>
#include<ctime>

using namespace std;

int main(){
	
	time_t t;
	t.localtime();
	cout<<t.gettime();
}
