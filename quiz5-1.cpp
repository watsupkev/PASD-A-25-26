#include <iostream>
#include <string.h>
using namespace std;

typedef struct{
	string nip;
	string nama_karyawan;
	int gaji;
} DataKaryawan;

typedef struct elm *alamatelm;
typedef struct elm{
	DataKaryawan kontainer;
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

void push(string nip, string nama_karyawan, int gaji, kue *k){
	elemen *info;
	info = new elemen;
	info -> kontainer.nip = nip;
	info -> kontainer.nama_karyawan = nama_karyawan;
	info -> kontainer.gaji = gaji;
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
			cout<<"Nomor Induk Pekerja		: "<<bantu -> kontainer.nip<<endl;
			cout<<"Nama Pekerja				: "<<bantu -> kontainer.nama_karyawan<<endl;
			cout<<"Gaji Pekerja			: "<<bantu -> kontainer.gaji<<endl;
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
	push("4525210033", "Kevin", 2000000, &k);
	push("4525210035", "Adam", 3000000, &k);
	push("4525210031", "Karel", 2500000, &k);
	push("4525210019", "Daffa", 4000000, &k);
	push("4525210013", "Domi", 2500000, &k);
	push("4525210003", "Ian", 2000000, &k);
	push("4525210113", "Satria", 2500000, &k);
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
	cout<<"=================================="<<endl;
	cin.get();
}
