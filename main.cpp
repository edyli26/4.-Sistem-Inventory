#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    char option;
    int maks_inv, maks_item, pilih,acak,hapus;//variabel
    vector<string> item{"Pisau . sts: 5","Pedang . sts 10"};
    vector<string> inve;
    vector<string>::iterator penunjuk;
    item.push_back("Pistol . sts: 15"); //untuk memasukan item
    item.push_back("Laser . sts: 20");
    item[2]="Batu . sts: 2"; // untuk mengganti item
    srand(static_cast<unsigned>(time(0))); // untuk mengacak

    maks_item=item.size();
    cout << "Maksimal item : "<< maks_item << endl; //masukan item
    cout << "Masukan Maks Inventory : "; cin >> maks_inv; //maksimal inventory

    do{

    cout << "\nMenu :" << endl;//pilihan menu
    cout << "1. Tampilkan Item" << endl;
    cout << "2. Tambah Item" << endl;
    cout << "3. Hapus Item" << endl;
    cout << "Pilih Menu : ";cin >> pilih;

    switch(pilih)
    {
        case 1://menunjukan inventory masih kosong
            if(inve.empty()){
                cout << "\nInvetory Masih Kosong" << endl;
            }else {
                cout << endl;
               for(penunjuk=inve.begin()  ; penunjuk != inve.end();penunjuk++){
                    cout << *penunjuk << endl;
                    }
                }
            break;
        case 2://menunjukan inventory sudah penuh`
            if(inve.size()>=maks_inv){
                cout << "\nInvetory Penuh " <<endl;
            }
            else{
            acak=rand()% maks_item;
            inve.push_back(item[acak]);
            cout << "\nItem yang ditambahkan adalah : "<< item[acak] << endl;
            }
            break;
        case 3://untuk mengahpus item
            cout << "\nHapus item ke-";cin >> hapus;
            if(hapus-1>=inve.size()){
                cout << "Item Yang dipilih tidak ada" << endl;
            }else{
            hapus=hapus-1;
            inve.erase(inve.begin()+hapus);
            }
            break;
        default:
            cout << "\nPilihan Salah" << endl;
            break;       }
    cout << "\nIngin Melanjutkan (y/n)? ";cin >> option;
    }while(option == 'y');//perulangan jika ingin melanjutkan game
    return 0;
}
