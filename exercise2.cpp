/*
Nama Program : Strukdat 11
Nama         : Hana Meilina Fauziyyah
NPM          : 140810180012
Tanggal buat : 15 Mei 2019
Deskripsi    : Tree
**********************************************/

#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Simpul{
    int info;
    Simpul* left;
    Simpul* right;
};

typedef Simpul* pointer;
typedef pointer Tree;

void createTree(Tree& Root);
void createSimpul(pointer& pBaru);
void insertBST (Tree& Root, pointer pBaru);
void preOrder (Tree Root);
void inOrder (Tree Root);
void postOrder (Tree Root);
int height(Tree Root);
void givenLevel(Tree Root, int level);
void levelOrder(Tree Root);
void depthOrder (Tree Root);
void printChildren(Tree Root, pointer pBaru);

main(){
    Tree t;
    pointer p;
    int n,pil;
    createTree(t);
    cout<<"Masukkan banyak elemen = ";
    cin>>n;
    for (int i=0;i<n;i++){
        createSimpul(p);
        insertBST(t,p);
    }
    cout<<"Tree telah dibuat"<<endl;
    getch();
    do{
      system("cls");
      cout<<"=-=-=-=-=-=-TREE=-=-=-=-=-=-=-="<<endl;
      cout<<"1. Insert"<<endl;
      cout<<"2. Preorder"<<endl;
      cout<<"3. Inorder"<<endl;
      cout<<"4. Postorder"<<endl;
      cout<<"5. Kedalaman"<<endl;
      cout<<"6. Level"<<endl;
      cout<<"7. Anak"<<endl;
      cout<<"8. Exit"<<endl;
      cout<<"Masukkan pilihan anda : ";
      cin>>pil;
      cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
      switch(pil){
           case 1 :
                createSimpul(p);
                insertBST(t,p);
                getch();
                cout<<"Tekan enter untuk kembali ke menu"<<endl;
                break;
           case 2 :
                cout<<"Pre Order"<<endl;
                preOrder(t);
                getch();
                cout<<"Tekan enter untuk kembali ke menu"<<endl;
                break;
           case 3 :
                cout<<"In Order"<<endl;
                inOrder(t);
                getch();
                cout<<"Tekan enter untuk kembali ke menu"<<endl;
                break;
           case 4 :
                cout<<"Post Order"<<endl;
                postOrder(t);
                getch();
                cout<<"Tekan enter untuk kembali ke menu"<<endl;
                break;
           case 5 :
                cout<<"Kedalaman Tree"<<endl;
                depthOrder(t);
                getch();
                cout<<"Tekan enter untuk kembali ke menu"<<endl;
                break;
           case 6 :
                cout<<"Level Tree"<<endl;
                levelOrder(t);
                getch();
                cout<<"Tekan enter untuk kembali ke menu"<<endl;
                break;
           case 7 :
                cout<<"Anak Tree"<<endl;
                printChildren(t,p);
                getch();
                cout<<"Tekan enter untuk kembali ke menu"<<endl;
                break;
            case 8 :
                exit(0);
                break;
            }
    }while(pil!=8);
}

void createTree(Tree& Root){
    Root=NULL;
}

void createSimpul(pointer& pBaru) {
    pBaru = new Simpul;
    cout<<"Masukkan angka : ";
    cin>>pBaru->info;
    pBaru->left = NULL;
    pBaru->right = NULL;
}

void insertBST (Tree& Root, pointer pBaru){
    if(Root==NULL)
        Root=pBaru;
    else if(pBaru->info<Root->info)
        insertBST(Root->left,pBaru);        //rekursif
    else if(pBaru->info>Root->info)
        insertBST(Root->right,pBaru);       //rekursif
    else
        cout<<"sudah ada";
}

// Traversal Tree ada 3 (Pre order, In order, post order)
void preOrder (Tree Root){
    if (Root != NULL){
        cout<<Root->info<<endl;
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder (Tree Root){
    if(Root != NULL){
        inOrder(Root->left);
        cout<<Root->info<<endl;
        inOrder(Root->right);
    }
}

void postOrder (Tree Root){
    if(Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<<Root->info<<endl;
    }
}

int height(Tree Root){
	if (Root==NULL)
        return 0;
	else{
		int lHeight=height(Root->left);
		int rHeight=height(Root->right);
		if (lHeight>rHeight)
            return (lHeight+1);
		else
            return (rHeight+1);
	}
}

void givenLevel(Tree Root, int level){
	if (Root==NULL)
        return;
	if (level==1)
        cout<<Root->info<<" ";
	else if (level>1){
		givenLevel(Root->left,level-1);
		givenLevel(Root->right,level-1);
	}
}

void levelOrder(Tree Root){
	int h=height(Root);
	for (int i=1; i<=h; i++){
		cout<<i<<" : ";
		givenLevel(Root,i);
		cout<<endl;
	}
}

void depthOrder (Tree Root){
	int h=height(Root);
	for (int i=1; i<=h; i++){
		cout<<i-1<<" : ";
		givenLevel(Root,i);
		cout << endl;
	}
}

void printChildren(Tree Root, pointer pBaru){
    pBaru=Root;
    if(pBaru!=NULL){
        cout<<"Parent : "<<pBaru->info<<endl;
        cout<<"Anak : "<<endl;
        if(pBaru->left==NULL)
            cout<<"Kiri : Tidak Ada"<<endl;
        else
            cout<<"Kiri : "<<pBaru->left->info<<endl;
        if(pBaru->right==NULL)
            cout<<"Kanan : Tidak Ada"<<endl;
        else
            cout<<"Kanan : "<<pBaru->right->info<<endl;
		cout<<endl;
		printChildren(Root->left, pBaru);
        printChildren(Root->right, pBaru);
    }
}
