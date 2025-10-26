#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

struct Data {
    string nama;
    string koordinat;
    bool terisi; 
    bool dihapus; 
};

int hashFunction(string nama) {
    int total = 0;
    for (char c : nama) {
        total += c;
    }
    return total % SIZE;
}

void initTable(Data table[]) {
    for (int i = 0; i < SIZE; i++) {
        table[i].terisi = false;
        table[i].dihapus = false;
    }
}

void insert(Data table[], string nama, string koordinat) {
    int index = hashFunction(nama);
    int start = index;
    do {
        if (!table[index].terisi || table[index].dihapus) {
            table[index].nama = nama;
            table[index].koordinat = koordinat;
            table[index].terisi = true;
            table[index].dihapus = false;
            return;
        }
        index = (index + 1) % SIZE; 
    } while (index != start);
    cout << "Tabel penuh, tidak bisa menambah data!\n";
}

int search(Data table[], string nama) {
    int index = hashFunction(nama);
    int start = index;
    do {
        if (table[index].terisi && table[index].nama == nama)
            return index;
        if (!table[index].terisi && !table[index].dihapus)
            return -1;
        index = (index + 1) % SIZE;
    } while (index != start);
    return -1;
}

void removeKey(Data table[], string nama) {
    int index = search(table, nama);
    if (index != -1) {
        table[index].terisi = false;
        table[index].dihapus = true;
        cout << "Data '" << nama << "' berhasil dihapus.\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }
}

void display(Data table[]) {
    cout << "\nIsi Hash Map (Navigasi Digital Unila):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        if (table[i].terisi)
            cout << "(" << table[i].nama << " -> " << table[i].koordinat << ")";
        else
            cout << "NULL";
        cout << endl;
    }
}

int main() {
    Data table[SIZE];
    initTable(table);

    insert(table, "Kampus Unila", "-5.364,105.242");
    insert(table, "Perpustakaan Unila", "-5.365,105.243");
    insert(table, "Stasiun Unila", "-5.366,105.240");
    insert(table, "Kantin Teknik", "-5.367,105.241");

    display(table);

    int idx = search(table, "Perpustakaan Unila");
    if (idx != -1)
        cout << "\nLokasi '" << table[idx].nama << "' ditemukan di koordinat " << table[idx].koordinat << endl;
    else
        cout << "\nLokasi tidak ditemukan!\n";

    removeKey(table, "Perpustakaan Unila");

    cout << "\nSetelah penghapusan:\n";
    display(table);

    return 0;
}
