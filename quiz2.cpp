#include <iostream>
using namespace std;

struct node{
	int kev; 
};
node *f;
int main(){
	f = new node;
	f -> kev = 50;
	cout <<f -> kev<<endl;
	cin.get();
}