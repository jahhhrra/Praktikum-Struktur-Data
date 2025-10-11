#include <iostream>
using namespace std;

int main () {

    int n;
    cout << "Masukkan jumlah botol: ";
    cin >> n;

    int tinggi[n];
    cout << "Masukkan tinggi setiap botol (cm): " << endl;
    for (int i=0; i<n; i++) {
        cout << "Botol ke-" << i+1 << ": ";
        cin >> tinggi[i];
    }

    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (tinggi[j] > tinggi[j+1]) {
                int temp = tinggi[j];
                tinggi[j] = tinggi[j+1];
                tinggi[j+1] = temp;
            }
        }
    }

    cout << "Tinggi botol setelah diurutkan: ";
    for (int i=0; i<n; i++) {
        cout << tinggi[i] << " ";
    }
    cout << endl;


    return 0;
}