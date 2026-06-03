#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>
using namespace std;

struct Node
{
    struct Node *Left;
	struct Node *Right;
    char INFO;
    struct Node *Link;
};

typedef struct Node Simpul;
Simpul *Root, *P, *Q, *LastCurrent, *Current, *LastKiri;
const int kiri = 0, kanan = 1;
int i, n, Flag, FlagHabis, Level;
char X, A[26] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void Inisialisasi()
{
    Root = NULL;
}
void BuatSimpul(char item)
{
    P = (Simpul*) malloc(sizeof(Simpul));
    if(P != NULL)
    {
        P -> INFO = item;
        P -> Left = NULL;
        P -> Right = NULL;
        P -> Link = NULL;
    }
    else
    {
        cout<<"Memory Penuh"<<endl;
        exit(1);
    }
}

void BuatSimpulAkar()
{
    if(Root == NULL)
    {
        Root = P;
        LastCurrent = Root;
        LastKiri = Root;
        Flag = kiri;
        Level = 0;
        n = 1;
        FlagHabis = 1;
    }
    else
    {
        cout<<"Pohon Sudah Ada"<<endl;
    }
}

void TambahSimpul()
{
    if(Root != NULL)
    {
        n = n+1;
        if(FlagHabis == 1)
        {
            FlagHabis = 0;
            Current = P;
            LastCurrent -> Left = P;
            Flag = kanan;
            Level = Level + 1;
        }
        else
        {
            if(Flag == kiri)
            {
                Flag = kanan;
                LastCurrent -> Left = P;
                Current -> Link = P;
                Current = P;
            }
            else
            {
                LastCurrent -> Right = P;
                Current -> Link = P;
                Flag = kiri;
                if(n == (pow(2, Level+1) - 1))
                {
                    FlagHabis = 1;
                    LastCurrent = LastKiri -> Left;
                    LastKiri = LastKiri -> Left;
                }
                else
                {
					LastCurrent = LastCurrent -> Link;
                }
            }
        }
    }
}

void BacaUrutNomor() {
    int i, j;
    Simpul *Q[129], *Current;
    i=1;    j=1;
    Q[i] = Root;
    while(Q[i] != NULL) {
        Current = Q[i];
        cout<< Current -> INFO << endl;
        if(Current -> Left != NULL){
            j++;
			Q[j]=Current -> Left;
        }
        if(Current -> Right != NULL){
            j++;
			Q[j] = Current -> Right;
        }
    i++;
    }
}

int main()
{
    int i,n;
    char X;
    int num[20] = {0, 22, 66, 28, 11, 7, 63, 14, 4, 10};
    char INFOx[20] = "PANCASILA";
    Inisialisasi();
    X = INFOx[0];
    BuatSimpul(X);
    BuatSimpulAkar();
    for(i=2; i<=8; i++)
    {
        n = num[i];
        X = INFOx[i];
        BuatSimpul(X);
        TambahSimpul();
    }
    BacaUrutNomor();
    cin.get();
}