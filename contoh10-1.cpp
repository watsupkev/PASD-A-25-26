#include<iostream>
using namespace std;

class BTreenode{
	int *kunci, t, n;
	bool leaf;
	BTreenode **c;
	
	public:
	BTreenode(int tt, bool _leaf);
	void sisipNfull(int k);
	void splitchild(int i, BTreenode *y);
	void traverse();
	BTreenode *search(int k);
	friend class BTree;
};

class BTree{
	int t;
	BTreenode *root;
	
	public:
		BTree(int tt)
		{root = NULL; t = tt;}
		void traverse()
		{if (root != NULL) root -> traverse();}
		
		BTreenode* search(int k)
		{return(root == NULL)? NULL : root->search(k);}
		void sisip(int k);
};

BTreenode::BTreenode(int t1, bool leaf1){
	t=t1;
	leaf=leaf1;
	kunci=new int [2*t-1];
	c = new BTreenode *[2*t];
	n=0;
}

void BTreenode::traverse(){
	int i;
	for (i=0;i<n;i++){
		if (leaf == false)
			c[i]->traverse();
			cout<<" "<<kunci[i];
	}
	if (leaf == false)
		c[i]->traverse();
}

BTreenode *BTreenode::search(int k){
	int i = 0;
	while (i<n && k>kunci[i])
		i++;
	if (kunci[i] == k)
		return this;
	if (leaf == true)
		return NULL;
	return c[i]->search(k);
}

void BTree::sisip(int k){
	if (root == NULL){
		root = new BTreenode(t, true);
		root->kunci[0] = k;
		root->n=1;
	}
	else {
		if (root->n==2*t-1){
			BTreenode *s = new BTreenode(t, false);
			s->c[0] = root;
			s->splitchild(0, root);
			int i=0;
			if (s->kunci[0]<k)
				i++;
			s->c[i]->sisipNfull(k);
			root=s;
		}
		else
			root->sisipNfull(k);
	}
}

void BTreenode::sisipNfull(int k){
	int i = n-1;
	if (leaf == true){
		while (i >= 0 && kunci[i] > k){
			kunci[i+1] = kunci[i];
			i--;
		}
		kunci[i+1] = k;
		n = n+1;
	}
	else{
		while (i >= 0 && kunci[i] > k)
			i--;
		if (c[i+1]->n==2*t-1){
			splitchild(i+1, c[i+1]);
			if (kunci[i+1] < k)
				i++;
		}
		c[i+1]->sisipNfull(k);
	}
}

void BTreenode::splitchild(int i, BTreenode *y){
	BTreenode *z = new BTreenode(y->t, y->leaf);
	z->n = t-1;
	for (int j=0; j<t-1; j++)
		z->kunci[j] = y->kunci[j+t];
	if (y->leaf==false){
		for (int j=0; j<t; j++)
			z->c[j] = y->c[j+t];
	}
	y->n = t-1;
	for (int j=n; j >= i+1; j--)
		c[j+1] = c[j];
		c[i+1] = z;
	for (int j=n-1; j >= i; j--)
		kunci[j+1] = kunci[j];
		kunci[i] = y->kunci[t-1];
	n=n+1;
}

int main(){
	BTree t(5);
	t.sisip(40);
	t.sisip(49);
	t.sisip(7);
	t.sisip(59);
	t.sisip(20);
	t.sisip(66);
	t.sisip(71);
	t.sisip(75);
	t.sisip(31);
	t.sisip(56);
	t.sisip(51);
	cout <<"pohon dengan menggunakan B-Tree"<<endl;
	cout <<"m = 5"<<endl;
	cout<<"--------------------------------"<<endl;
	t.traverse();
	cout<<endl;
	int k = 7;
	(t.search(k) != NULL)? cout<<"kunci yang dicari = "<<k<<" Ditemukan " : cout<<"kunci yang dicari = "<<k<<" tidak Ditemukan ";
	cout <<endl;
	k = 15;
	(t.search(k) != NULL)? cout<<"kunci yang dicari = "<<k<<" Ditemukan " : cout<<"kunci yang dicari = "<<k<<" tidak Ditemukan ";
	return 0;
}