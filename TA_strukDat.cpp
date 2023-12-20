#include <iostream> 
#include <iomanip> 

using namespace std;

void input (){}
void output (){}
void search (){}
void hapus (){}
void history (){}

main () {
    int menu;

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
        input();
        system("pause");
        break;
    case 2:
        output();
        system("pause");
        break;
    case 3:
        search();
        system("pause");
        break;
    case 4:
        hapus();
        system("pause");
        break;
    case 5:
        history();
        system("pause");
        break;
    
    default:
    back = 'n'; 
        break;
    }
}
}
