#include <iostream>
#include <string>
using namespace std;

int main () {

    string playlist [] = {"Red", "Exile", "Style", "Fearless", "Cardigan"};
    int n = 5;
    string cari;
    bool ketemu = false;

    cout << "Playlist: ";
    for (int i=0; i<n; i++) {
        cout << playlist[i] << " ";
    }

    cout << "\nMasukkan lagu yang ingin dicari: ";
    cin >> cari;

    for (int i=0; i<n; i++) {
        if (playlist[i] == cari) {
            cout << "Lagu " << cari << " ditemukan pada indeks ke-" << i << endl;
            ketemu = true;
            break;
        }
    }

    if (!ketemu) {
        cout << "Lagu " << cari << " tidak ditemukan di playlist" << endl;
    }

    return 0;
}