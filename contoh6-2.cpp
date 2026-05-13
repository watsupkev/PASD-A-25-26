#include <iostream>
using namespace std;

void merge(int arr[], int kiri, int mid, int kanan){
	int n1 = mid - kiri + 1;
	int n2 = kanan - mid;
	int l[n1], r[n2];
	for(int i=0;i<n1;i++){
		l[i] = arr[kiri+i];
	}
	for(int j=0;j<n2;j++){
		r[j] = arr[mid+1+j];
	}
	
	int i=0, j=0, k=kiri;
	
	while (i<n1 && j < n2){
		if (l[i] <= r[j]){
			arr[k] = l[i];
			i++;
		}
		else{
			arr[k] = r[j];
			j++;
		}
		k++;
	}
	while (i < n1){
		arr[k] = l[i];
		i++;
		k++;
	}
	while (j < n2){
		arr[k] = r[j];
		j++;
		k++;
	}
}

void mergesort(int arr[], int kiri, int kanan){
	if (kiri < kanan){
		int mid = kiri + (kanan - kiri) / 2;
		mergesort(arr, kiri, mid);
		mergesort(arr, mid+1, kanan);
		merge(arr, kiri, mid, kanan);
	}
}

void cekdata(int arr[],int size){
	for (int i = 0; i < size; i++){
		cout<<arr[i]<<" ";
	}
	cout <<endl;
}

int main(){
	int arr[]={65, 2, 44, 26, 19, 22, 5, 3, 12};
	int arrsize = sizeof(arr) / sizeof(arr[0]);
	
	cout<<"data sebelum diurut :";
	cekdata(arr, arrsize);
	
	mergesort(arr, 0, arrsize - 1);
	cout<<"data setelah diurut :";
	cekdata(arr, arrsize);
	
	cin.get();
}