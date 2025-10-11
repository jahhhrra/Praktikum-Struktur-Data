#include <iostream>
using namespace std;

const int MAX = 10;        
string chatStack[MAX];     
int topIdx = -1;           

bool isEmpty() { return topIdx == -1; }
bool isFull() { return topIdx == MAX - 1; }

void sendMessage(string pesan) {
    if (isFull()) {
        cout << "Kotak pesan penuh! Tidak bisa mengirim pesan lagi.\n";
        return;
    }
    chatStack[++topIdx] = pesan;
    cout << "Pesan terkirim: \"" << pesan << "\"\n";
}

void deleteMessage() {
    if (isEmpty()) {
        cout << "Tidak ada pesan untuk dihapus.\n";
        return;
    }
    cout << "Pesan \"" << chatStack[topIdx--] << "\" berhasil dihapus.\n";
}

void lastMessage() {
    if (isEmpty()) cout << "Belum ada pesan dikirim.\n";
    else cout << "Pesan terakhir: \"" << chatStack[topIdx] << "\"\n";
}

void showAllMessages() {
    if (isEmpty()) {
        cout << "Belum ada pesan dalam percakapan.\n";
        return;
    }
    cout << "=== Daftar Pesan Terkirim (Terbaru ke Terlama) ===\n";
    for (int i = topIdx; i >= 0; i--)
        cout << i + 1 << ". " << chatStack[i] << endl;
}

int main() {
    int pilih;
    string pesan;
    do {
        cout << "\n=== SIMULASI CHAT ONLINE (STACK ARRAY) ===\n";
        cout << "1. Kirim Pesan\n2. Hapus Pesan Terakhir\n3. Lihat Pesan Terakhir\n4. Lihat Semua Pesan\n5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            cout << "Ketik pesan: ";
            getline(cin, pesan);
            sendMessage(pesan);
        }
        else if (pilih == 2) deleteMessage();
        else if (pilih == 3) lastMessage();
        else if (pilih == 4) showAllMessages();

    } while (pilih != 5);

    return 0;
}
