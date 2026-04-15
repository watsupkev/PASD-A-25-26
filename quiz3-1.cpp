#include <iostream>
#include <string.h>
using namespace std;

typedef struct{
	string kodeBuku;
	string judulBuku;
	string pengarang;
} buku;

typedef struct elm *alamatelm;
typedef struct elm{
	buku kontainer;
	alamatelm next;
}elemen;

typedef struct{
	elemen* top;
} stack;

void buatSTkosong (stack *s){
	(*s).top = NULL;
}

int isKosong(stack s){
	bool hasil = false;
	
	if(s.top == NULL){
		hasil = true;
	}
	return hasil;
}

int jmlElemen(stack s){
	int hasil = 0;
	
	if(s.top != NULL){
		elemen *bantu;
		bantu = s.top;
		
		while(bantu != NULL){
			hasil = hasil + 1;
			bantu = bantu -> next;
		}
	}
	return hasil;
}

void push(string kodeBuku, string judulBuku, string pengarang, stack *s){
	elemen *info;
	info = new elemen;
	info -> kontainer.kodeBuku = kodeBuku;
	info -> kontainer.judulBuku = judulBuku;
	info -> kontainer.pengarang = pengarang;
	
	if((*s).top == NULL){
		cout <<"stack penuh"<<endl;
		info -> next = NULL;
	}
	else{
		info -> next = (*s).top;
	}
	(*s).top = info;
	info = NULL;
}

void Pop(stack *s){
	if((*s).top != NULL){
		elemen *hapus = (*s).top;
		if(jmlElemen(*s) == 1){
			(*s).top = NULL;
		}
		else {
			(*s).top = (*s).top -> next;
		}
		hapus -> next = NULL;
		delete hapus;
	}
	else {
		cout<<"stack kosong"<<endl;
	}
}

void CetakStack(stack s){
	if (s.top != NULL){
		cout<<"MENAMPILKAN STACK"<<endl;
		elemen *bantu = s.top;
		int i = 1;
		while(bantu != NULL){
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"Elemen ke				: "<< i << endl;
			cout<<"Kode Buku			: "<<bantu -> kontainer.kodeBuku<<endl;
			cout<<"Judul Buku			: "<<bantu -> kontainer.judulBuku<<endl;
			cout<<"Pengarang 			: "<<bantu -> kontainer.pengarang<<endl;
			bantu = bantu -> next;
			i = i + 1;	
		}
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	}
	else{
		cout<<"stack kosong"<<endl;
	}
}
int main(){
	stack s;
	buatSTkosong(&s);
	CetakStack(s);
	cout<<endl;
	cout<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	push("BK-001", "dreamybull ambatukam", "dreamybull", &s);
	push("BK-210", "kangkung dan nissan", "bundah-rahma", &s);
	push("BK-100", "lato-lato mojokerto", "PSHT", &s);
	CetakStack(s);
	cout<<"=================================="<<endl;
	cout<<endl;
	cout<<endl;
	Pop(&s);
	CetakStack(s);
	cout<<endl;
	cout<<endl;
	Pop(&s);
	CetakStack(s);
	cout<<endl;
	cout<<endl;
	Pop(&s);
	CetakStack(s);
	cout<<"=================================="<<endl;
	cin.get();
}
