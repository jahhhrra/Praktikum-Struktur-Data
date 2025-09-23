#include <iostream>
using namespace std;

void menu() {
    cout << "\n--- Program Nilai Siswa ---" << endl;
    cout << "1. Masukkan Nilai Siswa" << endl;
    cout << "2. Tampilkan Nilai Siswa" << endl;
    cout << "3. Keluar" << endl;
}

int main() {
    int nilaiSiswa[5];
    int pilihan;
    bool programBerjalan = true;

    while (programBerjalan) {
        menu();
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan 5 nilai siswa:" << endl;
                for (int i = 0; i < 5; i++) {
                    cout << "Nilai siswa ke-" << i + 1 << ": ";
                    cin >> nilaiSiswa[i];
                }
                cout << "Nilai berhasil disimpan." << endl;
                break;
            case 2:
                cout << "\n--- Daftar Nilai Siswa ---" << endl;
                for (int i = 0; i < 5; i++) {
                    cout << "Siswa ke-" << i + 1 << ": " << nilaiSiswa[i] << endl;
                }
                break;
            case 3:
                programBerjalan = false;
                cout << "Program selesai. Sampai jumpa!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    }

    return 0;
}