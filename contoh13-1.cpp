#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

const int HASHSIZE = 100;
struct HashData{
	char kode[50];
	char nama[100];
};
HashData* HashTable[HASHSIZE];

int charamount(char array[]){
	int jumlah=0;
	for(int i = 0; array[i]!='\0'; i++){
		jumlah++;
	}
	return jumlah;
}

bool isindexEmpty(int rec){
	if(HashTable[rec] == NULL){
		return true;
	}else{
		return false;
	}
}

int hashFunct(HashData *array){
	int value = 0, rec, n;
	
	n = charamount(array->kode);
	
	for(int i=0; i<n; i++)
		value += array->kode[i];
	
	rec = value % HASHSIZE;
	
	return rec;
}

void insert(HashData *array){
	int rec;
	rec = hashFunct(array);
	HashTable[rec] = array;
	
	cout <<"input successfull"<<endl;
	cout <<"data tersimpan pada indeks: "<<rec<<endl;
	cin.get();
}

int searchProc(HashData *cari, int rec){
	int m, n, j = 0;
	bool equal = true;
	if(isindexEmpty(rec) == false){
		n = charamount(cari->kode);
		m = charamount(HashTable[rec]->kode);
		if(n == m){
			while((equal == true) && (cari->kode[j] != '\0')){
				if(tolower(cari->kode[j]) != tolower(HashTable[rec]->kode[j]))
					equal = false;
				j++;
			}
			if(equal == true)
				return rec;
			else
				return +1;
		}
		else
			return +1;
	}
	else{
		return +1;
		cin.get();
	}
}

void searching(HashData *cari){
    int rec;
    
    rec = hashFunct(cari); 
    
    rec = searchProc(cari, rec);
    if(rec >= 0){
        cout<<"Data ditemukan pada record indeks "<<rec<<endl;
        cout<<"Isi data : "<<endl;
        cout<<"=> KodeMK      : "<<HashTable[rec]->kode<<endl;
        cout<<"=> Matakuliah  : "<<HashTable[rec]->nama<<endl;
    }
    else {
        cout<<"Maaf! Data tidak ditemukan."<<endl;
        cin.get();
    }
}


void deleting(HashData *hapus){
    int rec;
    
    rec = hashFunct(hapus); 
    
    rec = searchProc(hapus, rec);
    if(rec >= 0){
        cout<<"Data :"<<endl;
        cout<<"  => KodeMK      : "<<HashTable[rec]->kode<<endl;
        cout<<"  => MataKuliah  : "<<HashTable[rec]->nama<<endl;
        cout<<"terhapus!"<<endl;
        
        HashTable[rec] = NULL; 
    }
    else {
        cout<<"Maaf! Data tidak ditemukan!"<<endl;
        cin.get();
    }
}

void DisplayTable(){
    cout<<"\n";
    cout<<"|===================================================|"<<endl;
    cout<<"| Indeks |    KODEMK    |       Nama Mata Kuliah    |"<<endl;
    cout<<"|===================================================|"<<endl;
    for(int i = 0; i < HASHSIZE; i++)
    {
        if(isindexEmpty(i) == false)
            cout<<setw(6)<<i<<"      "<<HashTable[i]->kode<<"\t     "<<HashTable[i]->nama<<endl;
    }
    cin.get();
}

void Clear(){
    for(int i = 0; i < HASHSIZE; i++)
        HashTable[i] = NULL;
}


int main(){
    char ulang = 'Y', menu;
    do{
        system("cls");
        
        puts("        PROSES HASH TABLE        ");
        puts("");
        puts("1. Input");
        puts("2. Delete");
        puts("3. Find");
        puts("4. Display");
        puts("5. Clear");
        puts("x. Keluar");
        puts("");
        cout<<"Menu pilihan Anda : "; cin>>menu;
        
        switch(menu){
            case '1' :
                HashData *array;
                array = new HashData;
                puts("");
                cout<<"KodeMK        : "; cin>>array->kode;
                cout<<"Matakuliah    : "; cin>>array->nama;
                cout<<endl;
                insert(array); break;
            case '2' :
                HashData *hapus;
                hapus = new HashData;
                cout<<"Hapus Matakuliah(KodeMK) : "; cin>>hapus->kode;
                deleting(hapus); 
                cout << endl;
                system("pause"); 
				break;
            case '3' :
                HashData *cari;
                cari = new HashData;
                cout<<"Cari MataKuliah (KodeMK) : "; cin>>cari->kode;
                searching(cari); 
                cout << endl;
                system("pause"); 
				break;
            case '4' :
                DisplayTable(); break;
            case '5' :
                Clear();
                puts("Tabel hash telah dikosongkan."); 
                cout << endl;
                system("pause"); 
				break;
            case 'x' :
            case 'X' :
                ulang = 'T'; break;
            default :
                puts("Pilihan diluar Menu yang tersedia!"); break;
        }
        cin.get();
    }
    while(toupper(ulang) == 'Y');
    
    return 0;
}