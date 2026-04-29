#include <iostream>
#include <string.h>
using namespace std;

typedef struct{
	string kode_barang;
	string nama_barang;
	int jml_stock;
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

void push(string kode_barang, string nama_barang, int jml_stock, kue *k){
	elemen *info;
	info = new elemen;
	info -> kontainer.kode_barang = kode_barang;
	info -> kontainer.nama_barang = nama_barang;
	info -> kontainer.jml_stock = jml_stock;
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
			cout<<"Nomor Induk Pekerja		: "<<bantu -> kontainer.kode_barang<<endl;
			cout<<"Nama Pekerja				: "<<bantu -> kontainer.nama_barang<<endl;
			cout<<"Gaji Pekerja			: "<<bantu -> kontainer.jml_stock<<endl;
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
	push("4525210033", "babyoil", 20000, &k);
	push("4525210035", "minyak", 30000, &k);
	push("4525210031", "kapas", 25000, &k);
	push("4525210019", "handbody", 40000, &k);
	push("4525210013", "sabu", 25000, &k);
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
