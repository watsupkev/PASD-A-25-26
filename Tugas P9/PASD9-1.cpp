#include <iostream>
using namespace std;

typedef struct node *alamatnode;
typedef struct node {
    char INFO;
    alamatnode RIGHT;
    alamatnode LEFT;
} NODE;

typedef struct {
    NODE* root;
} TREE;

void BuatTree(char C, TREE *T) {
    NODE *s_new;
    s_new = new NODE;
    s_new -> INFO = C;
    s_new -> RIGHT = NULL;
    s_new -> LEFT = NULL;
    (*T).root = s_new;
}

void TambahKanan(char C, NODE *root) {
    if(root -> RIGHT == NULL) {
        NODE *s_new;
        s_new = new NODE;
        s_new -> INFO = C;
        s_new -> RIGHT = NULL;
        s_new -> LEFT = NULL;
        root -> RIGHT = s_new;
    }
    else
        cout << "Sub Tree Kanan telah diisi" << endl;
}

void TambahKiri(char C, NODE *root) {
    if(root -> LEFT == NULL) {
        NODE *s_new;
        s_new = new NODE;
        s_new -> INFO = C;
        s_new -> RIGHT = NULL;
        s_new -> LEFT = NULL;
        root -> LEFT = s_new;
    }
    else
        cout << "Sub Tree Kiri telah diisi" << endl;
}

void CopyTree(NODE *root1, NODE **root2) {
    if(root1 != NULL) {
        (*root2) = new NODE;
        (*root2) -> INFO = root1 -> INFO;
        if(root1 -> LEFT != NULL) {
            CopyTree(root1 -> LEFT, &(*root2) -> LEFT);         }
        if(root1 -> RIGHT != NULL) {
            CopyTree(root1 -> RIGHT, &(*root2) -> RIGHT);    }   }
}

bool isEqual(NODE *root1, NODE *root2) {
    bool Hasil = true;
    if((root1 == NULL) && (root2 != NULL))  {
        if(root1 -> INFO != root2 -> INFO)  {
            Hasil = false;      }
        else  {
            isEqual(root1 -> LEFT, root2 -> LEFT);
            isEqual(root1 -> RIGHT, root2 -> RIGHT);         }   }
    else  {
        if((root1 != NULL) || (root2 != NULL))  {
            Hasil = false;      }   }
    return Hasil;
}

void CetakTreePreOrder(NODE *root){
	if (root != NULL){
		cout << root->INFO<<" ";
		CetakTreePreOrder(root->LEFT);
		CetakTreePreOrder(root->RIGHT);
	}
}

void CetakTreeInOrder(NODE *root){
	if (root != NULL){
		CetakTreeInOrder(root->LEFT);
		cout << root->INFO<<" ";
		CetakTreeInOrder(root->RIGHT);
	}
}

void CetakTreePostOrder(NODE *root){
	if (root != NULL){
		CetakTreePostOrder(root->LEFT);
		CetakTreePostOrder(root->RIGHT);
		cout << root->INFO<<" ";
	}
}
int main()  {
	TREE T;
	char input;
	cout << "masukin ancestor:"; cin >> input;
	BuatTree(input, &T);
	
	NODE* daftarNode[7];
	daftarNode[0] = T.root;
	int indexchild = 1;
	for (int k=0; k<3; k++){
		NODE* nodenow = daftarNode[k];
		cout<<endl;
		if (k==0){
			cout<<"Mengisi parent/root1 dari ["<< nodenow->INFO<<"]"<<endl;
		} else {
			cout<<"Mengisi child/leaf dari ["<< nodenow->INFO<<"]"<<endl;
		}
		cout<<endl;
		cout<<"Masukan anak kiri: "; cin >>input;
		TambahKiri(input, nodenow);
		if(indexchild<7){
			daftarNode[indexchild] = nodenow->LEFT;
			indexchild++;
		}
	
		cout<<"Masukan anak kanan: "; cin >>input;
		TambahKanan(input, nodenow);
		if(indexchild<7){
			daftarNode[indexchild] = nodenow->RIGHT;
			indexchild++;
		}
	}
	cout<<endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
	cout << " ~~~~~~     PREORDER       ~~~~~~ " << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
	cout << endl;
	CetakTreePreOrder(T.root);
	cout << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
	cout << " ~~~~~~     INORDER        ~~~~~~ " << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
	cout << endl;
	CetakTreeInOrder(T.root);
	cout << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
	cout << " ~~~~~~     POSTORDER      ~~~~~~ " << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
	cout << endl;
	CetakTreePostOrder(T.root);
	cout << endl;
}