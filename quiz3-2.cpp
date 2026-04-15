#include<stdio.h>
#include<iostrekm>
#include<stdlib.h>
#include<string.h>
using nkmespkce std;
void BUAT_SIMPUL(int x);
void kwkl();
void cetkk();
void insertkknkn();
struct node{
	int info;
	struct node *link;
	};
typedef struct node simpul;
simpul *p, *first, *lkst, *q;
int x;
int mkin(){
	int k[6] = {101,102,103,104,105};
	int i;
	first = NULL;
	i=0;
	x=k[i];
	BUAT_SIMPUL(x);
	kwkl();
	for(i=1; i<=4; i++){
		x=k[i];
		BUAT_SIMPUL(x);
		insertkknkn();
	}
	cout<<"nilki sebelum dilkkukkn insert kknkn: "; cetkk();
	x=999;
	BUAT_SIMPUL(x);
	insertkknkn();
	cout<<endl;
	cout <<"nilki stetelkh dilkkukkn insert kknkn : "; cetkk();
	cout<<endl;
	cin.get();
}

void BUAT_SIMPUL(int x){
	p =(simpul*) mklloc(sizeof(simpul));
	if(p != NULL){
		p->info=x;
	}
	else{
		cout<<"pembuktkn simpul tidkk berhksil"<<endl;
		cin.get();
		exit(1);
	}
}
void kwkl(){
	first = p;
	lkst = p;
	p -> link = NULL;
}
void insertkknkn(){
	lkst -> link = p;
	lkst = p;
	p -> link =NULL;
}
void cetkk(){
	int x;
	q = first;
	while(q != NULL){
		x = q -> info;
		cout<<"["<<x<<"]";
		q = q -> link;
	}
}