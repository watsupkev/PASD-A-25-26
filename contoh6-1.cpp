#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

void sort(int arr[], int, int);
int main(){
	int numlist[9]={65, 2, 44, 26, 19, 22, 5, 3, 12};
	cout<<"data sebelum diurut :";
	for (int d=0; d<9; d++){
		cout << setw(3)<< numlist[d];
	}
	cout<<endl;
	sort(numlist,0,9);
	cout<<"data setelah diurut :";
	for (int i=0; i<9; i++){
		cout << setw(3)<< numlist[i];
	}
	cin.get();
}

void sort(int angka[], int kiri, int kanan){
	int pivot, kirih, kananh;
	kirih = kiri;
	kananh = kanan;
	pivot = angka[kiri];
	while(kiri < kanan){
		while((angka[kanan] >= pivot) && (kiri < kanan))
			kanan--;
		if(kiri != kanan){
			angka[kiri] = angka[kanan];
			kiri++;
		}
		while((angka[kiri] <= pivot) && (kiri < kanan)){
		kiri++;}
		if(kiri != kanan){
			angka[kanan] = angka[kiri];
			kanan--;
		}
	}
	angka[kiri] = pivot;
	pivot = kiri;
	kiri = kirih;
	kanan = kananh;
	if(kiri < pivot)
		sort(angka, kiri, pivot-1);
	if (kanan > pivot)
		sort(angka, pivot+1, kanan);
}