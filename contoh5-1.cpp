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
	elemen *first;
	elemen *last;
} kue;

void buatkuekosong (kue *k){
	(*k).first = NULL;
	(*k).last = NULL;
}

int isKosong(kue k){
	bool hasil = false;
	
	if(k.first == NULL){
		hasil = true;
	}
	return hasil;
}

int jmlElemen(kue k){
	int hasil = 0;
	
	if(k.first != NULL){
		elemen *bantu;
		bantu = k.first;
		
		while(bantu != NULL){
			hasil = hasil + 1;
			bantu = bantu -> next;
		}
	}
	return hasil;
}

void push(string npm, string nama_mhs, double nilai, kue *k){
	elemen *info;
	info = new elemen;
	info -> kontainer.npm = npm;
	info -> kontainer.nama_mhs = nama_mhs;
	info -> kontainer.nilai = nilai;
	info -> next = NULL;
	
	if((*k).first == NULL){
		(*k).first = info;
	}
	else{
		(*k).last -> next = info;
	}
	(*k).last = info;
	info = NULL;
}

void del(kue *k){
	if((*k).first != NULL){
		elemen *hapus = (*k).first;
		if(jmlElemen(*k) == 1){
			(*k).first = NULL;
			(*k).last = NULL;
		}
		else {
			(*k).first = (*k).first -> next;
			hapus -> next = NULL;
		}
		delete hapus;
	}
	else {
		cout<<"kue kosong"<<endl;
	}
}

void Cetakkue(kue k){
	if (k.first != NULL){
		cout<<"MENAMPILKAN QUEWE"<<endl;
		elemen *bantu = k.first;
		int i = 1;
		while(bantu != NULL){
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"Elemen ke				: "<< i << endl;
			cout<<"Nomor Pokok Mahasigma	: "<<bantu -> kontainer.npm<<endl;
			cout<<"Nama Mahasigma			: "<<bantu -> kontainer.nama_mhs<<endl;
			cout<<"Nilai Mahasigma			: "<<bantu -> kontainer.nilai<<endl;
			bantu = bantu -> next;
			i = i + 1;	
		}
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	}
	else{
		cout<<"kue kosong"<<endl;
	}
}
int main(){
	kue k;
	buatkuekosong(&k);
	Cetakkue(k);
	cout<<endl;
	cout<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	push("4525210033", "Kevin", 88.75, &k);
	push("4525210035", "Adam", 78.85, &k);
	push("4525210031", "Karel", 58.65, &k);
	push("4525210019", "Daffa", 68.55, &k);
	Cetakkue(k);
	cout<<"=================================="<<endl;
	cout<<endl;
	cout<<endl;
	del(&k);
	Cetakkue(k);
	cout<<endl;
	cout<<endl;
	del(&k);
	Cetakkue(k);
	cout<<endl;
	cout<<endl;
	del(&k);
	Cetakkue(k);
	cout<<"=================================="<<endl;
	cin.get();
}
