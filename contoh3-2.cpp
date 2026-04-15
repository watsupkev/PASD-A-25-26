#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void BUAT_SIMPUL(int x);
void awal();
void cetak();
void insertkanan();
struct node{
	int info;
	struct node *link;
	};
typedef struct node simpul;
simpul *p, *first, *last, *q;
int x;
int main(){
	int a[7] = {22,28,7,11,66,63,10};
	int i;
	first = NULL;
	i=0;
	x=a[i];
	BUAT_SIMPUL(x);
	awal();
	for(i=1; i<=6; i++){
		x=a[i];
		BUAT_SIMPUL(x);
		insertkanan();
	}
	cout<<"nilai sebelum dilakukan insert kanan: "; cetak();
	x=100;
	BUAT_SIMPUL(x);
	insertkanan();
	cout<<endl;
	cout <<"nilai stetelah dilakukan insert kanan : "; cetak();
	cout<<endl;
	cin.get();
}

void BUAT_SIMPUL(int x){
	p =(simpul*) malloc(sizeof(simpul));
	if(p != NULL){
		p->info=x;
	}
	else{
		cout<<"pembuatan simpul tidak berhasil"<<endl;
		cin.get();
		exit(1);
	}
}
void awal(){
	first = p;
	last = p;
	p -> link = NULL;
}
void insertkanan(){
	last -> link = p;
	last = p;
	p -> link =NULL;
}
void cetak(){
	int x;
	q = first;
	while(q != NULL){
		x = q -> info;
		cout<<" "<<x;
		q = q -> link;
	}
}