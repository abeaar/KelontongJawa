#include <iostream> 
#include <iomanip> 
#define max 20
using namespace std;

struct node
{
    string nama;
    int harga, kode;
    node *kanan, *kiri;
};
node *akar, *p, *b, *bantu, *del, *NB;
node *hashTable[max],*awal[max], *akhir[max];


void buathash(){
    for (int i = 0; i < max; i++)
    {
        hashTable[i]=new node;
        hashTable[i]= NULL;
        awal[i]= hashTable[i];
        akhir[i] = hashTable[i];
    }
}

void buat_ptb (){
    node *ptb;
    ptb=NULL;
    akar=ptb;
}

int ptb_kosong(){
    if (akar==NULL)
    return (true);
    else return (false);
}

void sisipHash(int kodenode, string namanode, int harganode){
int key;
    key = kodenode % max;
    NB = new node;
    NB -> kode = kodenode;
    NB -> kanan = NULL;
    NB -> kiri = NULL;

    if (awal[key]==NULL){
        awal[key]=NB;
        akhir[key]=NB;
    }
    else{
        akhir[key]-> kanan = NB;
        NB-> kiri = akhir[key];
        akhir[key] = NB;
    }
}

void sisipPtb(int kodenode, string namanode, int harganode){
   node *NB;
   NB = new node;
   NB->kode = kodenode;
   NB->nama = namanode;
   NB->harga = harganode;
   NB->kiri = NULL;
   NB->kanan = NULL;
   if (ptb_kosong())
   {
    akar = NB;
   } else {
        b=akar;
        p=akar;
        while (p!=NULL && namanode !=b->nama){
            b=p;
            if (namanode<p-> nama)
                p=b-> kiri;
            else 
                p=b-> kanan;
        }
            if (namanode<b-> nama)
                b->kiri=NB;
            else
                b->kanan=NB;
    }
   
}

void input (){
int banyak, inputharga, inputkode;
string inputnama;
cout << "Masukan Data Barang : " << endl; 
    for (char lagi = 'y'; lagi == 'y';)
    {
        cout << endl;
        cout << "kode  : " ; cin >> inputkode;
        cout << "nama  : " ; cin >> inputnama;
        cout << "harga : " ; cin >> inputharga;
        cout << endl;
        sisipPtb (inputkode, inputnama, inputharga);
        sisipHash (inputkode, inputnama, inputharga);
        cout << "Input lagi ? [y/n] : "; cin >> lagi;
    }

}

void preorder(node *akar){
    if (akar!= NULL){
        cout <<" "<<akar-> nama ;
        preorder (akar->kiri);
        preorder (akar->kanan);
    }
}

void inorder(node *akar){
    if (akar != NULL){
        inorder (akar-> kiri);
        cout <<" "<<akar-> nama;
        inorder (akar-> kanan);
    }
}

void postorder (node *akar){
    if (akar != NULL){
        postorder (akar -> kiri);
        postorder (akar-> kanan);
        cout <<" "<<akar-> nama;
    }
}
void bacaHash(){
    cout << "Table Hash nya :" << endl;
    for (int i = 0; i < max; i++){
    if(awal[i]!=0){
        bantu = awal[i];
        cout << endl << bantu-> kode;
        while (bantu->kanan!= NULL){
            bantu = bantu-> kanan;
            cout << " -> "<< bantu -> kode;
        }
            cout << endl;
    }
    }
}
void output(){
    cout << "\nPre-order : ";
    preorder(akar);
    cout <<"\nIn-order : ";
    inorder(akar);
    cout << "\nPost-order : ";
    postorder(akar);
    cout << endl;
    bacaHash();
    return;
}

void searchHash(int carikode) {
    
}
void searchPTB(string cariNama) {

}

void search(){
    int menu, carikode;
    string cariNama;
    for (char back = 'y'; back =='y';){
        cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
        cout << "|    Selamat Datang di Menu Pencarian     |"<< endl;
        cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
        cout << "| ID Barang                               |"<< endl;
        cout << "| Nama Barang                             |"<< endl;
        cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
        cout << "pilih :"<< endl;
        switch (menu)
        {
        case 1:
            cout << "Masukan ID yang ingin dicari : "; cin >> carikode;
            system("cls");
            searchHash(carikode);
            system("pause");
            break;
        case 2:
            cout << "Masukan Nama yang ingin dicari : "; cin >> cariNama;
            system("cls");
            searchPTB(cariNama);
            system("pause");
            break;
        default:
            break;
        }
    
    }
}
void hapus(){

}
void history(){}

main () {
    int menu;
    buat_ptb();
for (char back='y'; back=='y'; ) {

    system ("cls");
    cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
    cout << "|     SELAMAT DATANG DI TOKO SERBA ADA    |"<< endl;
    cout <<"|"<< setw (42) << setfill ('=') << '|' << endl;
    cout << "| 1. input                                |"<< endl;
    cout << "| 2. output                               |"<< endl;
    cout << "| 3. search                               |"<< endl;
    cout << "| 4. delete                               |"<< endl;
    cout << "| 5. cek history                          |"<< endl;
    cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
    cout << "| 6. exit                                 |"<< endl;
    cout <<"|"<< setw (42) << setfill ('-') << '|' << endl;
    cout << "pilih : ";
    cin>>menu;
    switch (menu)
    {
    case 1:
        system("cls");
        input();
        system("pause");
        break;
    case 2:
        system("cls");
        output();
        system("pause");
        break;
    case 3:
        system("cls");
        search();
        system("pause");
        break;
    case 4:
        system("cls");
        hapus();
        system("pause");
        break;
    case 5:
        system("cls");
        history();
        system("pause");
        break;
    
    default:
    back = 'n'; 
        break;
    }
}
}
