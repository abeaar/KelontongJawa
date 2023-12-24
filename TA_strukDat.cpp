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
node *akarHistory, *pHistory, *bHistory;
node hashTable[max], *awal[max], *akhir[max];


void buathash(){
    for (int i = 0; i < max; i++)
    {
        hashTable[i].kode = -1;
    }
}

void buat_ptb (){
    node *ptb;
    ptb=NULL;
    akar=ptb;
}

void buat_ptb_history (){
    node *ptb;
    ptb=NULL;
    akar=ptb;
}

int ptb_kosong(){
    if (akar==NULL)
    return (true);
    else return (false);
}

int ptb_history_kosong(){
    if (akarHistory==NULL)
    return (true);
    else return (false);
}

void sisipHash(int kodenode, string namanode, int harganode){
    int key;
    key = kodenode % max;
    int initialkey = key;
	while (awal[key] != nullptr && awal[key]->kode != kodenode) {
        key = (key + 1) % max;  
        if (key == initialkey) {
            cout << "Tabel penuh. Tidak dapat menyisipkan data." << endl;
            return;
        }
    }

    NB = new node;
    NB -> kode = kodenode;
    NB -> nama = namanode;
    NB -> harga = harganode;

    hashTable[key].kode = kodenode;
    hashTable[key].nama = namanode;
    hashTable[key].harga = harganode;

    NB -> kanan = NULL;
    NB -> kiri = NULL;

    if (awal[key]==NULL){
        awal[key]=NB;
        akhir[key]=NB;
    }
    else{
        akhir[key]->kanan = NB;
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

void sisipPtbHistory(int kodenode, string namanode, int harganode){
   node *NB;
   NB = new node;
   NB->kode = kodenode;
   NB->nama = namanode;
   NB->harga = harganode;
   NB->kiri = NULL;
   NB->kanan = NULL;
   if (ptb_history_kosong())
   {
    akarHistory = NB;
   } else {
        bHistory=akarHistory;
        pHistory=akarHistory;
        while (pHistory!=NULL && namanode !=bHistory->nama){
            bHistory=pHistory;
            if (namanode<pHistory-> nama)
                pHistory=bHistory-> kiri;
            else 
                pHistory=bHistory-> kanan;
        }
            if (namanode<bHistory-> nama)
                bHistory->kiri=NB;
            else
                bHistory->kanan=NB;
    }
}

void input (){
int inputharga, inputkode;
string inputnama;
        cout <<"+"<< setw (42) << setfill ('=') << '+' << endl;
        cout << "|     Selamat Datang di Menu Input        |"<< endl;
        cout <<"+"<< setw (42) << setfill ('=') << '+' << endl;
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
        cout <<akar-> nama << ", ";
        preorder (akar->kiri);
        preorder (akar->kanan);
    }
}

void inorder(node *akar){
    if (akar != NULL){
        inorder (akar-> kiri);
        cout <<akar-> nama << ", ";
        inorder (akar-> kanan);
    }
}

void postorder (node *akar){
    if (akar != NULL){
        postorder (akar -> kiri);
        postorder (akar-> kanan);
        cout <<akar-> nama << ", ";
    }
}
void bacaHash(){
        cout << "Daftar barang : " << endl << endl;
        cout <<"+"<< setw (53) << setfill ('-') << '+' << endl;
        cout << "| Kode    | Nama                | harga              |" << endl;
        cout <<"+"<< setw (53) << setfill ('-') << '+' << endl;
        for(int i = 0; i < max; i++){
        if(hashTable[i].kode != -1){
            cout << "| " << left << setw(8) << setfill(' ') << hashTable[i].kode;
            cout << "| " << setw(20) << setfill(' ') << hashTable[i].nama;
            cout << "| Rp. " << setw(15) << setfill(' ') << hashTable[i].harga << "|"<< endl;
        }
    }
        cout <<"+"<< setw (53) << setfill ('-') << '+' << endl;
}
void output(){
        cout <<"+"<< setw (42) << setfill ('=') << '+' << endl;
        cout << "|      Selamat Datang di Menu output      |"<< endl;
        cout <<"+"<< setw (42) << setfill ('=') << '+' << endl;
    bacaHash();
    return;
}

void searchHash(int carikode) {
    int key = carikode % max;
    int initialkey = key;
while (hashTable[key].kode != carikode) {
        key = (key + 1) % max;
        if (key == initialkey) {
            break; 
}
}

    if (awal[key] != nullptr && awal[key]->kode == carikode) {
        cout << "Data ditemukan pada hash key " << key << " :\n";
        cout <<"+"<< setw (53) << setfill ('-') << '+' << endl;
        cout << "| Kode    | Nama                | harga              |" << endl;
        cout <<"+"<< setw (53) << setfill ('-') << '+' << endl;
        cout << "| " << left << setw(8) << setfill(' ') << awal[key]->kode;
        cout << "| " << setw(20) << setfill(' ') << awal[key]->nama;
        cout << "| Rp. " << setw(15) << setfill(' ') << awal[key]->harga << "|"<< endl;
        cout <<"+"<< setw (53) << setfill ('-') << '+' << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

void searchPTB(string cariNama) {
	if (!ptb_kosong()) {
        bantu = akar;
        while (bantu != NULL && bantu->nama != cariNama) {
            if (cariNama < bantu->nama) {
                bantu = bantu->kiri;
            } else {
                bantu = bantu->kanan;
            }
        }
        
        if (bantu != NULL && bantu->nama == cariNama) {
            cout << "Data ditemukan pada PTB:\n";
            cout <<"+"<< setw (53) << setfill ('-') << '+' << endl;
            cout << "| Kode    | Nama                | harga              |" << endl;
            cout <<"+"<< setw (53) << setfill ('-') << '+' << endl;
            cout << "| " << left << setw(8) << setfill(' ') << bantu->kode;
            cout << "| " << setw(20) << setfill(' ') << bantu->nama;
            cout << "| Rp. " << setw(15) << setfill(' ') << bantu->harga << "|"<< endl;
            cout <<"+"<< setw (53) << setfill ('-') << '+' << endl;            
        } else {
            cout << "Data tidak ditemukan." << endl;
        }
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
}

void search(){
    int menu, carikode;
    string cariNama;
    for (char back = 'n'; back =='n';){
    system("cls");
        cout <<"+"<< setw (42) << setfill ('=') << '+' << endl;
        cout << "|    Selamat Datang di Menu Pencarian     |"<< endl;
        cout <<"+"<< setw (42) << setfill ('=') << '+' << endl;
        cout << "| 1. ID Barang                            |"<< endl;
        cout << "| 2. Nama Barang                          |"<< endl;
        cout << "| 3. back                                 |"<< endl;
        cout <<"+"<< setw (42) << setfill ('-') << '+' << endl;
        cout << "pilih : ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "\nList kode :" << endl; 
                for(int i = 0; i < max; i++){
                if(hashTable[i].kode != -1){
                    cout << hashTable[i].kode << ", ";
                }
            }
            cout << endl;
            cout << "\nMasukan ID yang ingin dicari : "; cin >> carikode;
            searchHash(carikode);
            break;
        case 2:
            cout << "\nList Nama :" << endl;
            postorder(akar);
            cout << endl;
            cout << "\nMasukan Nama yang ingin dicari : "; cin >> cariNama;
            searchPTB(cariNama);
            break;
        default:
            break;
        }
		cout << "\n";
		cout << "Kembali ke menu utama? [y/n] : "; 
		cin >> back;
    }
}
void hapus(){
    int carikode;
    string nama;
        cout <<"+"<< setw (42) << setfill ('=') << '+' << endl;
        cout << "|      Selamat Datang di Menu Hapus       |"<< endl;
        cout <<"+"<< setw (42) << setfill ('=') << '+' << endl;

    bacaHash();

    cout << "kode barang yg ingin dihapus : "; cin >> carikode;

    // cari key
    int key = carikode % max;
    int initialkey = key;

while (hashTable[key].kode != carikode) {
        key = (key + 1) % max;
        if (key == initialkey) {
            break; 
}
}

    if(hashTable[key].kode != -1){
        char yakin;
        cout << "Yakin ingin hapus?[y/n] : "; cin >> yakin;
        
        if(yakin == 'y' || yakin == 'Y'){
            //delete hash
            sisipPtbHistory(hashTable[key].kode, hashTable[key].nama, hashTable[key].harga);
            hashTable[key].kode = -1;
            awal[key] = nullptr;

            //delete ptb
            b = akar;
            p = akar;
            while (p != NULL && hashTable[key].nama != p->nama) {
                b = p;
                if (hashTable[key].nama < p->nama)
                    p = b->kiri;
                else
                    p = b->kanan;
        }
    
            node *temp;
            if (p->kiri == NULL && p->kanan == NULL) {
                if (b == akar && p == akar)
                    akar = NULL;
                else {
                    if (p == b->kiri)
                        b->kiri = NULL;
                    else
                        b->kanan = NULL;
                }
                delete p;
            } else if (p->kiri != NULL && p->kanan != NULL) {
                temp = p->kiri;
                b = p;
                while (temp->kanan != NULL) {
                    b = temp;
                    temp = temp->kanan;
                }
                p->kode = temp->kode;
                p->nama = temp->nama;
                p->harga = temp->harga;
                if (b == p)
                    b->kiri = temp->kiri;
                else
                    b->kanan = temp->kiri;
                delete temp;
            } else if (p->kiri != NULL && p->kanan == NULL) {
                if (b == p)
                    akar = p->kiri;
                else {
                    if (p == b->kiri)
                        b->kiri = p->kiri;
                    else
                        b->kanan = p->kiri;
                }
                delete p;
            } else if (p->kiri == NULL && p->kanan != NULL) {
                if (b == p)
                    akar = p->kanan;
                else {
                    if (p == b->kanan)
                        b->kanan = p->kanan;
                    else
                        b->kiri = p->kanan;
                }
                delete p;
            }
                }

    } else {
        cout << "\nDATA TIDAK DITEMUKAN\n";
    }
}

void history(){
    cout <<"+"<< setw (42) << setfill ('=') << '+' << endl;
    cout << "|     SELAMAT DATANG DI Menu History      |"<< endl;
    cout <<"+"<< setw (42) << setfill ('=') << '+' << endl;
    cout << "HISTORY BARANG\n\n";
    cout << "Preorder  : "; preorder(akarHistory); cout << endl;
    cout << "Inorder   : "; inorder(akarHistory); cout << endl;
    cout << "Postorder : "; postorder(akarHistory); cout << endl;
}

main () {
    int menu;
    buat_ptb();
    buat_ptb_history();
    buathash();
for (char back='y'; back=='y'; ) {

    system ("cls");
    cout <<"+"<< setw (42) << setfill ('=') << '+' << endl;
    cout << "|     SELAMAT DATANG DI TOKO SERBA ADA    |"<< endl;
    cout <<"+"<< setw (42) << setfill ('=') << '+' << endl;
    cout << "| 1. input                                |"<< endl;
    cout << "| 2. output                               |"<< endl;
    cout << "| 3. search                               |"<< endl;
    cout << "| 4. delete                               |"<< endl;
    cout << "| 5. cek history                          |"<< endl;
    cout <<"+"<< setw (42) << setfill ('-') << '+' << endl;
    cout << "| 6. exit                                 |"<< endl;
    cout <<"+"<< setw (42) << setfill ('-') << '+' << endl;
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
