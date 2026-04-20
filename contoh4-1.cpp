#include <iostream>
#include <string>
using namespace std;

typedef struct{
	string npm;
	string nama_mhs;
	double nilai;
} nilaimk;

typedef struct{
	int first;
	int last;
	nilaimk dat[10];
}queue;

void buatqkosong(queue *q){
	(*q).first= -1;
	(*q).last= -1;
}

bool iskosong(queue q){
	bool hasil = false;
	
	if(q.first == -1){
		hasil = true;
	}
	return hasil;
}

bool ispenuh(queue q){
	bool hasil = false;
	
	if(q.last == 9){
		hasil = true;
	}
	return hasil;
}

void add(string npm, string nama_mhs, double nilai, queue *q){
	if(iskosong(*q) == 1){
		(*q).first = 0;
		(*q).last = 0;
		(*q).dat[0].npm = npm;
		(*q).dat[0].nama_mhs = nama_mhs;
		(*q).dat[0].nilai = nilai;
	}
	else{
		if(ispenuh(*q) != 1){
			(*q).last = (*q).last+1;
			(*q).dat[(*q).last].npm = npm;
			(*q).dat[(*q).last].nama_mhs = nama_mhs;
			(*q).dat[(*q).last].nilai = nilai;
		}
		else{
			cout <<"kuewe penuh"<<endl;
		}
	}
}

void del(queue *q){
	if((*q).last == 0){
		(*q).first = -1;
		(*q).last = -1;
	}
	else {
		int i;
		for(i=((*q).first + 1); i <= (*q).last; i++){
			(*q).dat[i-1].npm=(*q).dat[i].npm;
			(*q).dat[i-1].nama_mhs=(*q).dat[i].nama_mhs;
			(*q).dat[i-1].nilai=(*q).dat[i].nilai;
		}
		(*q).last=(*q).last-1;
	}
}

void cetakqueue(queue q){
	if(q.first!=-1){
		cout<<"Menampilkan queue"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~"<<endl;
		int i;
		for (i=q.last;i>=q.first;i--){
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"Elemen ke             : "<<i<<endl;
			cout<<"Nomor Pokok Mahasiswa : "<<q.dat[i].npm<<endl;
			cout<<"Nama Mahasiswa        : "<<q.dat[i].nama_mhs<<endl;
			cout<<"Nilai Mahasiswa       : "<<q.dat[i].nilai<<endl;}}
	else{
		cout<<"queue Kosong"<<endl;}}

int main(){
	queue q;
	buatqkosong(&q);
	cetakqueue(q);
	cout<<endl;
	cout<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	add("4523210666","Budi",88.75,&q);
	add("4523210777","Susi",78.85,&q);
	add("4523210888","Nuri",68.65,&q);
	add("4523210999","Bimo",78.55,&q);
	add("4523210555","Arif",78.55,&q);
	add("4523210444","Rido",78.55,&q);
	add("4523210222","Ella",78.55,&q);
	cetakqueue(q);
	cout<<"========================================"<<endl;
	cout<<endl;
	cout<<endl;
	del(&q);
	cetakqueue(q);
	cout<<endl;
	cout<<endl;
	del(&q);
	cetakqueue(q);
	cout<<"========================================"<<endl;
	return 0;
}