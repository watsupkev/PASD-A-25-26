#include <iostream>
#include <string.h>
using namespace std;

typedef struct{
	string npm;
	string nama_mhs;
	double nilai;
} NilaiMK;

typedef struct elm *alamatelm;
typedef struct elm{
	NilaiMK kontainer;
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

void push(string npm, string nama_mhs, double nilai, stack *s){
	elemen *info;
	info = new elemen;
	info -> kontainer.npm = npm;
	info -> kontainer.nama_mhs = nama_mhs;
	info -> kontainer.nilai = nilai;
	
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
			cout<<"Nomor Pokok Mahasigma	: "<<bantu -> kontainer.npm;
			cout<<"Nama Mahasigma			: "<<bantu -> kontainer.nama_mhs<<endl;
			cout<<"Nilai Mahasigma			: "<<bantu -> kontainer.nilai<<endl;
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
	push("4525210033", "Kevin", 88.75, &s);
	push("4525210035", "Adam", 78.85, &s);
	push("4525210031", "Karel", 58.65, &s);
	push("4525210019", "Daffa", 68.55, &s);
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
