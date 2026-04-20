#include <iostream>
#include <string.h>
using namespace std;
#define max 100
#define true 1
#define false 0

struct biodata{
	char nama[20];
	int usia;
};
struct biodata mhs;
struct biodata queue[max];
void init(void);
int full (void);
int empty(void);
struct biodata entridata(void);
void enqueue(struct biodata mhs);
struct biodata dequeue(void);
void display(struct biodata mhs);
void baca(void);
int awal, akhir;
char nocomment[10];

int main(){
	char pilih;
	cout<<"pilih entri"<<endl;
	init();
	do{
		cout<<"1. Input Data\n";
		cout<<"2. Hapus Data\n";
		cout<<"3. lihat Data Mahasiswa\n";
		cout<<"4. Hapus Semua Data\n";
		cout<<"5. selesai\n";
		cout<<"pilih 1 sd 5 : "; cin >>pilih;
		switch(pilih){
			case '1': mhs = entridata();enqueue(mhs); break;
			case '2': cout<<"data di hapus : \n"; mhs = dequeue(); display(mhs); break;
			case '3': baca(); break;
			case '4': init();cout<<"\ndata telah dikosongkan\n";break;
			case '5': break;
			default: cout<<" "; break;
		}
		cout<<endl;
	}
	while(pilih != '5');
	return 0;
}

void init(void){
	awal=-1;
	akhir=-1;}

void enqueue(struct biodata mhs){
	if(empty()==true){
		awal=0;
		akhir=0;
		queue[awal]=mhs;}
	else if(full()!=true){
		akhir++;
		queue[akhir]=mhs;}
	else cout<<"Queue sudah penuh..."<<endl;}
	
struct biodata dequeue(void){
	int i;
	if(empty()!=true){
		mhs=queue[awal];
		for(i=awal;i<=akhir;i++)
			queue[i]=queue[i+1];
		akhir--;
		return(mhs);}
	else cout<<"Queue Kosong..."<<endl;}
	
int full(void){
	if(akhir==max-1)return(true);
	else return(false);}
	
int empty(void){
	if(akhir==-1) return(true);
	else return(false);}
	
void baca(void){
	int i;
	cout<<"Isi Queue : "<<endl;
	if(empty()!=true){
		for(i=awal;i<=akhir;i++){
			display(queue[i]);}
	}else cout<<"Data Kosong"<<endl;}
	
struct biodata entridata(void){
	struct biodata mhs;
	cout<<endl;
	cout<<"Masukkan Nama : ";cin>>mhs.nama;
	cout<<"Masukkan Usia : ";cin>>mhs.usia;
	return(mhs);}
	
void display(struct biodata mhs){
	cout<<endl;
	cout<<"Nama : "<<mhs.nama<<endl;
	cout<<"Usia : "<<mhs.usia<<endl;}