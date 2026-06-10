#include <iostream>
using namespace std;

void HEAP(int CanArray[], int n, int i){
	int temp, canbesar=i, kiri=2*i+1, kanan=2*i+2;
	if(kiri < n && CanArray[kiri] > CanArray[canbesar])
		canbesar = kiri;
	if(kanan < n && CanArray[kanan] > CanArray[canbesar])
		canbesar = kanan;
	if(canbesar != i){
		temp = CanArray[i];
		CanArray[i] = CanArray[canbesar];
		CanArray[canbesar] = temp;
		HEAP(CanArray, n, canbesar);
	}
}

void sort(int CanArray[], int n){
	int temp;
	for (int i = n/2-1; i>=0; i--)
		HEAP(CanArray, n, i);
	for(int i=n-1; i>=0; i--){
		temp = CanArray[0];
		CanArray[0] = CanArray[i];
		CanArray[i] = temp;
		HEAP(CanArray, i, 0);
	}
}

int main(){
	int CanArray[] = {22, 7, 66, 28, 11, 63, 24, 12, 77, 99};
	int n=10, i;
	cout<<"data sebelum diurut :";
	for (i=0; i<n; i++)
		cout<<CanArray[i]<<" ";
	sort(CanArray, n);
	cout<<endl;
	cout<<"data setelah diurut :";
	for (i=0; i<n; ++i)
		cout<<CanArray[i]<<" ";
	cin.get();
}