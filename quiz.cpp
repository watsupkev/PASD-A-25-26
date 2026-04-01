#include <iostream>
#include <string>
using namespace std;

int main(){
	struct Kev_BUKU{
		string JudulBuku;
		char pengarang[10];
		int tTerbit;
		float Harga;
	};
	Kev_BUKU Data_Buku;
	Data_Buku.JudulBuku = "cara mencari epstein file";
	Data_Buku.pengarang = "ambatukam";
	Data_Buku.tTerbit = 2026;
	Data_Buku.Harga = 200000;
	cout<<"Judul Buku		= "<<Data_Buku.JudulBuku<<endl;
	cout<<"Nama Pengarang	= "<<Data_Buku.pengarang<<endl;
	cout<<"Tahun Terbit		= "<<Data_Buku.tTerbit<<endl;
	cout<<"Harga			= "<<Data_Buku.Harga<<"Rp"<<endl;
	cin.get();
}