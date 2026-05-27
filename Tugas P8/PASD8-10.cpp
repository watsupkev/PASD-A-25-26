#include<iostream>
using namespace std;

struct struk{
	int arr;
	char kev[5];
	char SearchElemen;
	int flag;
};

int Search01(char A[], int, int);
int main()
{
	struk sam = {5, {'f', 'k', 'd', 's', 'a'}, ' ', 0};
	cout << "========================================" <<endl;
	cout << "** S E Q U E N T I A L    S E A R C H **" <<endl;
	cout << "========================================" <<endl;
	//gotoxy(1,5);
	cout << "Isi data nya adalah" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~" << endl;
	cout << endl;
	for(int index=0; index<sam.arr; index++)
	{
		cout << "\t" << "Data [" << index << "] " << "--> " << sam.kev[index]<<endl;
	}
	cout << "========================================" <<endl;
	cout << endl;
	cout << "Masukkan data yang akan Anda cari ?   "; cin >> sam.SearchElemen;
	
	sam.flag = Search01(sam.kev, sam.arr, sam.SearchElemen);
	if(sam.flag != -1)
		cout << "Data yang dicari ditemukan pada posisi : Data["<< sam.flag <<"]"<<endl;
	else
		cout << "Data yang Anda cari tidak ditemukan" << endl;
	cin.get();
}
int Search01(char A[],int arr, int Elemen)
{
	int flag = -1;
	for(int index=0; index<arr; index++)
	{
		if(Elemen==A[index])
		{
			flag=index;
			break;
		}
	}
	return flag;
}