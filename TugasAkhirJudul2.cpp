#include <iostream>
using namespace std;

void tukar (int *x, int *y);

int main () {
    int n;
    int harga[1005];
    string menu[1005];

    cout << "Masukkan jumlah menu: ";
    cin >> n;

    cout << "Masukkan nama menu dan harganya (contoh: NasiGoreng 12000)\n";
    for (int i = 0; i < n; i++) {
        cout << "Menu ke-" << i+1 << ": ";
        cin >> menu[i] >> harga[i];
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (harga[j] > harga[j+1]) {
                tukar(&harga[j], &harga[j+1]);
                swap(menu[j], menu[j+1]); 
            }
        }
    }

    cout << "\nDaftar menu setelah diurutkan dari termurah ke termahal:\n";
    for (int i = 0; i < n; i++) {
        cout << menu[i] << " - Rp" << harga[i] << endl;
    }

    return 0;
}

void tukar (int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}
