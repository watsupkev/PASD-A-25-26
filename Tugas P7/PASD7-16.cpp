#include <iostream>
#include <iomanip>
using namespace std;
struct struk{
	int A[9];
	int n = 9;
    int X;
};
int main() {
    struk kev;
    int angka[] = {65, 2, 44, 26, 19, 22, 5, 3, 12};
    for (int k=0; k<kev.n; k++){
		kev.A[k] = angka[k];
	}
    cout << "data sebelum diurut :";
    for (int s = 0; s < kev.n; s++) {
        cout <<" "<< kev.A[s];
    }
    cout << endl;
    int k = 0;
    int flag = 1;
    while (k <= kev.n - 2 && flag == 1) {
        int i = 0;
        flag = 0;
        while (i <= kev.n - 2 - k) {
            if (kev.A[i] > kev.A[i+1]) { 
                flag = 1;
                kev.X = kev.A[i];
                kev.A[i] = kev.A[i+1];
                kev.A[i+1] = kev.X;
            }
            i++;
        }
        k++;
    }
    cout << "data setelah diurut :";
    for (int f = 0; f < kev.n; f++) {
        cout << " " << kev.A[f];
    }
    cout << endl;
    cin.get();
}