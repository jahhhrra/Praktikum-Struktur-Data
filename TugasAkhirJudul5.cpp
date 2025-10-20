#include <iostream>
using namespace std;

struct Node {
    int harga;
    Node* left;
    Node* right;
    Node(int h): harga(h), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int harga) {
    if (!root) return new Node(harga);
    if (harga < root->harga) root->left = insertNode(root->left, harga);
    else if (harga > root->harga) root->right = insertNode(root->right, harga);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->harga << " ";
    inorder(root->right);
}

bool searchNode(Node* root, int harga) {
    if (!root) return false;
    if (root->harga == harga) return true;
    if (harga < root->harga) return searchNode(root->left, harga);
    return searchNode(root->right, harga);
}

int main() {
    Node* root = nullptr;
    int pilih, harga;

    do {
        cout << "\n=== Sistem Data Harga Barang (BST) ===\n";
        cout << "1. Tambah harga barang\n";
        cout << "2. Lihat daftar harga (urut)\n";
        cout << "3. Cari harga barang\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan harga barang: ";
            cin >> harga;
            root = insertNode(root, harga);
        } 
        else if (pilih == 2) {
            cout << "Daftar harga (murah ke mahal): ";
            inorder(root);
            cout << "\n";
        } 
        else if (pilih == 3) {
            cout << "Masukkan harga yang ingin dicari: ";
            cin >> harga;
            cout << (searchNode(root, harga) ? "Harga ditemukan\n" : "Harga tidak ditemukan\n");
        }
    } while (pilih != 4);

    return 0;
}
