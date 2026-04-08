#include <iostream>
using namespace std;

class barang {
	public:
    string kode;
    char nama[20];
    float harga;
};
int main(){
	barang kevin;
	cout<<"masukan Kode Barang		: "; getline(cin,kevin.kode);
	cout<<"masukan Nama Nama		: "; cin >> kevin.nama;
	cout<<"masukan Harga			: "; cin >> kevin.harga;
	cout<<endl;
	cout<<"=================================="<<endl;
	cout<<"	BARANG YANG DI TENTUKAN	"<<endl;
	cout<<"=================================="<<endl;
	cout<<"Kode Barang		= "<<kevin.kode<<endl;
	cout<<"Nama Barang		= "<<kevin.nama<<endl;
	cout<<"Harga Barang		= "<<kevin.harga<<endl;
	cin.get();
}